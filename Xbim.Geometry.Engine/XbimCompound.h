#pragma once
#include "XbimSolid.h"
#include "XbimShell.h"
#include "XbimFace.h"

#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopExp_Explorer.hxx>
#include <Precision.hxx>

using namespace System::Collections::Generic;
using namespace XbimGeometry::Interfaces;
using namespace Xbim::Ifc2x3::TopologyResource;
namespace Xbim
{
	namespace Geometry
	{
		//a set of Xbim Geometry Objects
		ref class XbimCompound : IXbimGeometryObjectSet, XbimOccShape
		{
		private:
			
			IntPtr ptrContainer;
			virtual property TopoDS_Compound* pCompound
			{
				TopoDS_Compound* get() sealed { return (TopoDS_Compound*)ptrContainer.ToPointer(); }
				void set(TopoDS_Compound* val)sealed { ptrContainer = IntPtr(val); }
			}
			XbimCompound(){};
			static XbimCompound^ empty = gcnew XbimCompound();
			bool _isSewn;
			double _sewingTolerance;
			void InstanceCleanup();
			//Initialisers
			void Init(IfcConnectedFaceSet^ faceSet);
			void Init(IEnumerable<IfcFace^>^ faces);
			void Init(IfcShellBasedSurfaceModel^ sbsm);
			void Init(IfcFaceBasedSurfaceModel^ fbsm);
			void Init(IfcManifoldSolidBrep^ solid);
			void Init(IfcFacetedBrep^ solid);
			void Init(IfcFacetedBrepWithVoids^ solid);
			void Init(IfcClosedShell^ solid);
			//Helpers
			XbimFace^ BuildFace(List<Tuple<XbimWire^, IfcPolyLoop^, bool>^>^ wires, IfcFace^ face);
			static void  GetConnected(HashSet<XbimSolid^>^ connected, Dictionary<XbimSolid^, HashSet<XbimSolid^>^>^ clusters, XbimSolid^ clusterAround);
			
			
		public:
			~XbimCompound(){ InstanceCleanup(); }
			!XbimCompound(){ InstanceCleanup(); }
			XbimCompound(double sewingTolerance);
			XbimCompound(const TopoDS_Compound& compound, bool sewn, double tolerance);
			XbimCompound(IfcConnectedFaceSet^ faceSet);
			XbimCompound(IfcShellBasedSurfaceModel^ sbsm);
			XbimCompound(IfcFaceBasedSurfaceModel^ fbsm);
			XbimCompound(IfcManifoldSolidBrep^ solid);
			XbimCompound(IfcFacetedBrep^ solid);
			XbimCompound(IfcFacetedBrepWithVoids^ solid);
			XbimCompound(IfcClosedShell^ solid);
			static property XbimCompound^ Empty{XbimCompound^ get(){ return empty; }};
#pragma region IXbimCompound Interface
			virtual property bool IsValid {bool get()override{ return ptrContainer != IntPtr::Zero && Count > 0; }; }
			virtual property bool IsSet{bool get() override { return true; }; }
			virtual property  XbimGeometryObjectType GeometryType  {XbimGeometryObjectType  get()override { return XbimGeometryObjectType::XbimGeometryObjectSetType; }}
			virtual property int Count{int get(); }
			virtual property IXbimGeometryObject^ First{IXbimGeometryObject^ get(); }
			virtual IXbimGeometryObject^ Transform(XbimMatrix3D matrix3D) override;
			virtual IXbimGeometryObject^ TransformShallow(XbimMatrix3D matrix3D) override;
			static List<XbimSolid^>^  GetDiscrete(List<XbimSolid^>^%);
			virtual property IXbimSolidSet^ Solids {IXbimSolidSet^ get(); }
			virtual property IXbimShellSet^ Shells{IXbimShellSet^ get(); }
			virtual property IXbimFaceSet^ Faces{IXbimFaceSet^ get(); }
			virtual property IXbimEdgeSet^ Edges{IXbimEdgeSet^ get(); }
			virtual property IXbimVertexSet^ Vertices{IXbimVertexSet^ get(); }
			virtual void Add(IXbimGeometryObject^ geomObj);
			virtual IXbimGeometryObjectSet^ Cut(IXbimSolidSet^ solids, double tolerance);
			virtual IXbimGeometryObjectSet^ Cut(IXbimSolid^ solid, double tolerance);
			virtual IXbimGeometryObjectSet^ Union(IXbimSolidSet^ solids, double tolerance);
			virtual IXbimGeometryObjectSet^ Union(IXbimSolid^ solid, double tolerance);
			virtual IXbimGeometryObjectSet^ Intersection(IXbimSolidSet^ solids, double tolerance);
			virtual IXbimGeometryObjectSet^ Intersection(IXbimSolid^ solid, double tolerance);
			
#ifdef OCC_6_9_SUPPORTED //OCC 6.9.0. is better with complex booleans
			static int MaxFacesToSew = 3000;
#else
			static int MaxFacesToSew = 1000;
#endif
#pragma endregion
			//operators
			operator const TopoDS_Compound& () { return *pCompound; }
			virtual operator const TopoDS_Shape& () override { return *pCompound; }
			virtual property bool IsSewn{bool get(){ return _isSewn; }}
			virtual IEnumerator<IXbimGeometryObject^>^ GetEnumerator();
			virtual System::Collections::IEnumerator^ GetEnumerator2() = System::Collections::IEnumerable::GetEnumerator{return GetEnumerator();}
			//Upgrades the result to the highest level and simplest object without loss of representation
			IXbimGeometryObject^ Upgrade();
			IXbimShell^ MakeShell();
			static XbimCompound^ Merge(IXbimSolidSet^ solids, double tolerance);
			XbimCompound^ Cut(XbimCompound^ solids, double tolerance);
			XbimCompound^ Union(XbimCompound^ solids, double tolerance);
			XbimCompound^ Intersection(XbimCompound^ solids, double tolerance);
			virtual property XbimRect3D BoundingBox {XbimRect3D get()override ; }
			virtual property double Volume{double get(); }
			
			bool Sew();
			//moves the compound to the new position
			void Move(IfcAxis2Placement3D^ position);
		};

	}
}