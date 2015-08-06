#include "XbimGeometryObjectSet.h"
#include "XbimSolidSet.h"
#include "XbimShellSet.h"
#include "XbimFaceSet.h"
#include "XbimEdgeSet.h"
#include "XbimVertexSet.h"
#include "XbimGeometryCreator.h"

#include <TopTools_IndexedMapOfShape.hxx>
#include <TopExp.hxx>
#include <BRep_Builder.hxx>

#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepTools.hxx>
using namespace System;
namespace Xbim
{
	namespace Geometry
	{
		XbimGeometryObjectSet::XbimGeometryObjectSet(IEnumerable<IXbimGeometryObject^>^ objects)
		{
			geometryObjects = gcnew List<IXbimGeometryObject^>(objects);
		}

		XbimGeometryObjectSet::XbimGeometryObjectSet()
		{
			geometryObjects = gcnew List<IXbimGeometryObject^>();
		}

		IXbimGeometryObject^ XbimGeometryObjectSet::First::get()
		{
			if (geometryObjects->Count == 0) return nullptr;
			return geometryObjects[0];
		}

		int XbimGeometryObjectSet::Count::get()
		{
			return geometryObjects->Count;
		}

		IEnumerator<IXbimGeometryObject^>^ XbimGeometryObjectSet::GetEnumerator()
		{
			return geometryObjects->GetEnumerator();
		}

		IXbimGeometryObject^ XbimGeometryObjectSet::Transform(XbimMatrix3D matrix3D)
		{
			List<IXbimGeometryObject^>^ result = gcnew List<IXbimGeometryObject^>(geometryObjects->Count);
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				result->Add(geomObj->Transform(matrix3D));
			}
			return gcnew XbimGeometryObjectSet(result);
		}

		IXbimGeometryObject^ XbimGeometryObjectSet::TransformShallow(XbimMatrix3D matrix3D)
		{
			List<IXbimGeometryObject^>^ result = gcnew List<IXbimGeometryObject^>(geometryObjects->Count);
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				result->Add(((XbimGeometryObject^)geomObj)->TransformShallow(matrix3D));
			}
			return gcnew XbimGeometryObjectSet(result);
		}

		XbimRect3D XbimGeometryObjectSet::BoundingBox::get()
		{
			XbimRect3D result = XbimRect3D::Empty;
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				XbimRect3D bbox = geomObj->BoundingBox;
				if (result.IsEmpty) result = bbox;
				else
					result.Union(bbox);
			}
			return result;
		}

		IXbimSolidSet^ XbimGeometryObjectSet::Solids::get()
		{
			XbimSolidSet^ solids = gcnew XbimSolidSet();
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				XbimOccShape^ occ = dynamic_cast<XbimOccShape^>(geomObj);
				XbimSolidSet^ ss = dynamic_cast<XbimSolidSet^>(geomObj);
				if (occ!=nullptr)
				{
					TopTools_IndexedMapOfShape map;
					TopExp::MapShapes(occ, TopAbs_SOLID, map);					
					for (int i = 1; i <= map.Extent(); i++)
						solids->Add(gcnew XbimSolid(TopoDS::Solid(map(i))));					
				}
				else if (ss!=nullptr)
				{
					for each (XbimSolid^ solid in ss)
					{
						solids->Add(ss);
					}		
				}

			}
			return solids;
		}

		IXbimShellSet^ XbimGeometryObjectSet::Shells::get()
		{
			List<IXbimShell^>^ shells = gcnew List<IXbimShell^>();
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				XbimOccShape^ occ = dynamic_cast<XbimOccShape^>(geomObj);
				XbimShellSet^ ss = dynamic_cast<XbimShellSet^>(geomObj);
				if (occ != nullptr)
				{
					TopTools_IndexedMapOfShape map;
					TopExp::MapShapes(occ, TopAbs_SHELL, map);
					for (int i = 1; i <= map.Extent(); i++)
						shells->Add(gcnew XbimShell(TopoDS::Shell(map(i))));
				}
				else if (ss != nullptr)
				{
					for each (XbimShell^ shell in ss)
					{
						shells->Add(shell);
					}
				}
			}
			return gcnew XbimShellSet(shells);
			
		}

		IXbimFaceSet^ XbimGeometryObjectSet::Faces::get()
		{
			List<IXbimFace^>^ faces = gcnew List<IXbimFace^>();
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				XbimOccShape^ occ = dynamic_cast<XbimOccShape^>(geomObj);
				XbimFaceSet^ fs = dynamic_cast<XbimFaceSet^>(geomObj);
				if (occ != nullptr)
				{
					TopTools_IndexedMapOfShape map;
					TopExp::MapShapes(occ, TopAbs_FACE, map);
					for (int i = 1; i <= map.Extent(); i++)
						faces->Add(gcnew XbimFace(TopoDS::Face(map(i))));
				}
				else if (fs != nullptr)
				{
					for each (XbimFace^ face in fs)
					{
						faces->Add(face);
					}
				}
			}
			return gcnew XbimFaceSet(faces);			
		}

		IXbimEdgeSet^ XbimGeometryObjectSet::Edges::get()
		{
			List<IXbimEdge^>^ edges = gcnew List<IXbimEdge^>();
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				XbimOccShape^ occ = dynamic_cast<XbimOccShape^>(geomObj);
				XbimEdgeSet^ es = dynamic_cast<XbimEdgeSet^>(geomObj);
				if (occ != nullptr)
				{
					TopTools_IndexedMapOfShape map;
					TopExp::MapShapes(occ, TopAbs_EDGE, map);
					for (int i = 1; i <= map.Extent(); i++)
						edges->Add(gcnew XbimEdge(TopoDS::Edge(map(i))));
				}
				else if (es != nullptr)
				{
					for each (XbimEdge^ edge in es)
					{
						edges->Add(edge);
					}
				}
			}
			return gcnew XbimEdgeSet(edges);			
		}

		IXbimVertexSet^ XbimGeometryObjectSet::Vertices::get()
		{
			List<IXbimVertex^>^ vertices = gcnew List<IXbimVertex^>();
			for each (IXbimGeometryObject^ geomObj in geometryObjects)
			{
				XbimOccShape^ occ = dynamic_cast<XbimOccShape^>(geomObj);
				XbimVertexSet^ vs = dynamic_cast<XbimVertexSet^>(geomObj);
				if (occ != nullptr)
				{
					TopTools_IndexedMapOfShape map;
					TopExp::MapShapes(occ, TopAbs_VERTEX, map);
					for (int i = 1; i <= map.Extent(); i++)
						vertices->Add(gcnew XbimVertex(TopoDS::Vertex(map(i))));
				}
				else if (vs != nullptr)
				{
					for each (XbimVertex^ vertex in vs)
					{
						vertices->Add(vertex);
					}
				}
			}
			return gcnew XbimVertexSet(vertices);
		}


		bool XbimGeometryObjectSet::ParseGeometry(IEnumerable<IXbimGeometryObject^>^ geomObjects, TopTools_ListOfShape& toBeProcessed, Bnd_Array1OfBox& aBoxes,
			TopoDS_Shell& passThrough, double tolerance)
		{

			BRep_Builder builder;
			TopoDS_Shell facesToBeCut;
			builder.MakeShell(facesToBeCut);
			bool hasFacesToProcess = false;
			bool hasObjectsToProcess = false;
			for each (IXbimGeometryObject^ iGeom in geomObjects)
			{			
				XbimShell^ shell = dynamic_cast<XbimShell^>(iGeom);
				XbimSolid^ solid = dynamic_cast<XbimSolid^>(iGeom);
				IEnumerable<IXbimGeometryObject^>^ geomSet = dynamic_cast<IEnumerable<IXbimGeometryObject^>^>(iGeom);
				XbimFace^ face = dynamic_cast<XbimFace^>(iGeom);
				
				if (solid != nullptr)
				{
					toBeProcessed.Append(solid);
					hasObjectsToProcess = true;
					
					//BRepTools::Write((XbimOccShape^)solid, "d:\\tmp\\b");
					
				}
				else if (shell != nullptr)
				{
					for (TopExp_Explorer expl(shell, TopAbs_FACE); expl.More(); expl.Next())
					{
						Bnd_Box bbFace;
						BRepBndLib::Add(expl.Current(), bbFace);
						for (int i = 1; i <= aBoxes.Length(); i++)
						{
							if (!bbFace.IsOut(aBoxes(i)))
							{
								//check if the face is not sitting on the cut
								builder.Add(facesToBeCut, expl.Current());
								hasFacesToProcess = true;
							}
							else
								builder.Add(passThrough, expl.Current());
						}
					}
				}
				else if (geomSet != nullptr)
				{
					if (ParseGeometry(geomSet, toBeProcessed, aBoxes, passThrough, tolerance)) //nothing to do so just return what we had
					{
						hasObjectsToProcess = true;
					}
				}
				else if (face != nullptr)
				{
					Bnd_Box bbFace;
					BRepBndLib::Add(face, bbFace);
					for (int i = 1; i <= aBoxes.Length(); i++)
					{
						if (!bbFace.IsOut(aBoxes(i)))
						{
							//check if the face is not sitting on the cut
							builder.Add(facesToBeCut, face);
							hasFacesToProcess = true;
						}
						else
							builder.Add(passThrough, face);
					}
				}
			}
			if (hasFacesToProcess)
			{
				hasObjectsToProcess = true;
				//sew the bits we are going to cut
				BRepBuilderAPI_Sewing seamstress(tolerance);
				seamstress.Add(facesToBeCut);
				seamstress.Perform();
				toBeProcessed.Append(seamstress.SewedShape());
			}
			return hasObjectsToProcess;
		}

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::PerformBoolean(BOPAlgo_Operation bop, IXbimGeometryObject^ geomObject, IXbimSolidSet^ solids, double tolerance)
		{

			List<IXbimGeometryObject^>^ geomObjects = gcnew List<IXbimGeometryObject^>();
			geomObjects->Add(geomObject);
			return PerformBoolean(bop, geomObjects, solids, tolerance);
		}

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::PerformBoolean(BOPAlgo_Operation bop, IEnumerable<IXbimGeometryObject^>^ geomObjects, IXbimSolidSet^ solids, double tolerance)
		{
			String^ err = "";
			BRepAlgoAPI_BooleanOperation* pBuilder = nullptr;
			try
			{
				//get the subset of faces that intersect the openings
				//we are going to treat shells different from solids by only cutting those faces that intersect the cut

				TopoDS_Shell toBePassedThrough;
				TopoDS_Shell facesToCut;
				BRep_Builder builder;
				builder.MakeShell(facesToCut);
				builder.MakeShell(toBePassedThrough);
				TopTools_ListOfShape toBeProcessed;

				TopTools_ListOfShape cuttingObjects;

				int allBoxCount = 0;
				Bnd_Array1OfBox allBoxes(1, solids->Count);

				int i = 1;
				
				
				for each (XbimSolid^ solid in solids)
				{
					if (solid->IsValid)
					{
						/*char buff[128];
						sprintf(buff, "d:\\tmp\\o%d", i);
						BRepTools::Write(solid, buff);*/
						cuttingObjects.Append(solid);
						Bnd_Box box;
						BRepBndLib::Add(solid, box);
						allBoxes(i++).SetGap(-tolerance * 2); //reduce to only catch faces that are inside tolerance and not sitting on the opening
					}
					
				}

				if (!ParseGeometry(geomObjects, toBeProcessed, allBoxes, toBePassedThrough, tolerance)) //nothing to do so just return what we had
					return gcnew XbimGeometryObjectSet(geomObjects);
				switch (bop) {
				case BOPAlgo_COMMON:
					pBuilder = new BRepAlgoAPI_Common();
					break;
				case BOPAlgo_FUSE:
					pBuilder = new BRepAlgoAPI_Fuse();
					break;
				case BOPAlgo_CUT:
					pBuilder = new BRepAlgoAPI_Cut();
					break;
				case BOPAlgo_SECTION:
					pBuilder = new BRepAlgoAPI_Section();
					break;
				default:
					break;
				}
				
				pBuilder->SetArguments(toBeProcessed);

				pBuilder->SetTools(cuttingObjects);
				pBuilder->SetFuzzyValue(tolerance);
				pBuilder->Build();

				if (pBuilder->ErrorStatus() == 0)
				{
					//BRepTools::Write(pBuilder->Shape(), "d:\\tmp\\r");
					TopoDS_Compound occCompound;
					builder.MakeCompound(occCompound);
					builder.Add(occCompound, pBuilder->Shape());
					XbimCompound^ compound = gcnew XbimCompound(occCompound, false, tolerance);
					if (bop != BOPAlgo_COMMON) //do not need to add these as they by definition do not intersect
					{
						compound->Add(gcnew XbimShell(toBePassedThrough));
					}
					XbimGeometryObjectSet^ geomObjs = gcnew XbimGeometryObjectSet();
					geomObjs->Add(compound);
					if (pBuilder != nullptr) delete pBuilder;
					
					//BRepTools::Write(toBePassedThrough, "d:\\tmp\\s");
					return geomObjs;
					
				}
				GC::KeepAlive(solids);
				GC::KeepAlive(geomObjects);
			}
			catch (Standard_Failure e)
			{
				err = gcnew String(Standard_Failure::Caught()->GetMessageString());				
			}
		//	XbimGeometryCreator::logger->WarnFormat("WS032: Boolean Cut operation failed. " + err);
			if (pBuilder != nullptr) delete pBuilder;
			return XbimGeometryObjectSet::Empty;
		}

		

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::Cut(IXbimSolidSet^ solids, double tolerance)
		{						
			return PerformBoolean(BOPAlgo_CUT, (IEnumerable<IXbimGeometryObject^>^)this, solids, tolerance);
		}

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::Cut(IXbimSolid^ solid, double tolerance)
		{
			if (Count == 0) return XbimGeometryObjectSet::Empty;
			return PerformBoolean(BOPAlgo_CUT, (IEnumerable<IXbimGeometryObject^>^)this, gcnew XbimSolidSet(solid), tolerance);
		}
		

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::Union(IXbimSolidSet^ solids, double tolerance)
		{
			return PerformBoolean(BOPAlgo_FUSE, (IEnumerable<IXbimGeometryObject^>^)this, solids, tolerance);
		}

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::Union(IXbimSolid^ solid, double tolerance)
		{
			if (Count == 0) return XbimGeometryObjectSet::Empty;
			return PerformBoolean(BOPAlgo_FUSE, (IEnumerable<IXbimGeometryObject^>^)this, gcnew XbimSolidSet(solid), tolerance);
		}

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::Intersection(IXbimSolidSet^ solids, double tolerance)
		{
			return PerformBoolean(BOPAlgo_COMMON, (IEnumerable<IXbimGeometryObject^>^)this, solids, tolerance);
		}

		IXbimGeometryObjectSet^ XbimGeometryObjectSet::Intersection(IXbimSolid^ solid, double tolerance)
		{
			if (Count == 0) return XbimGeometryObjectSet::Empty;
			return PerformBoolean(BOPAlgo_COMMON, (IEnumerable<IXbimGeometryObject^>^)this, gcnew XbimSolidSet(solid), tolerance);
		}
	}
}
