// Created on: 1998-10-29
// Created by: Jean Yves LEBEY
// Copyright (c) 1998-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _TopOpeBRep_Hctxff2d_HeaderFile
#define _TopOpeBRep_Hctxff2d_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TopoDS_Face.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
#include <MMgt_TShared.hxx>
#include <Standard_Integer.hxx>
class BRepAdaptor_HSurface;
class TopoDS_Face;


class TopOpeBRep_Hctxff2d;
DEFINE_STANDARD_HANDLE(TopOpeBRep_Hctxff2d, MMgt_TShared)


class TopOpeBRep_Hctxff2d : public MMgt_TShared
{

public:

  
  Standard_EXPORT TopOpeBRep_Hctxff2d();
  
  Standard_EXPORT void SetFaces (const TopoDS_Face& F1, const TopoDS_Face& F2);
  
  Standard_EXPORT void SetHSurfaces (const Handle(BRepAdaptor_HSurface)& S1, const Handle(BRepAdaptor_HSurface)& S2);
  
  Standard_EXPORT void SetTolerances (const Standard_Real Tol1, const Standard_Real Tol2);
  
  Standard_EXPORT void GetTolerances (Standard_Real& Tol1, Standard_Real& Tol2) const;
  
  Standard_EXPORT Standard_Real GetMaxTolerance() const;
  
  Standard_EXPORT const TopoDS_Face& Face (const Standard_Integer I) const;
  
  Standard_EXPORT Handle(BRepAdaptor_HSurface) HSurface (const Standard_Integer I) const;
  
  Standard_EXPORT Standard_Boolean SurfacesSameOriented() const;
  
  Standard_EXPORT Standard_Boolean FacesSameOriented() const;
  
  Standard_EXPORT Standard_Boolean FaceSameOrientedWithRef (const Standard_Integer I) const;




  DEFINE_STANDARD_RTTI(TopOpeBRep_Hctxff2d,MMgt_TShared)

protected:




private:

  
  Standard_EXPORT void SetHSurfacesPrivate();

  TopoDS_Face myFace1;
  Handle(BRepAdaptor_HSurface) mySurface1;
  GeomAbs_SurfaceType mySurfaceType1;
  Standard_Boolean myf1surf1F_sameoriented;
  TopoDS_Face myFace2;
  Handle(BRepAdaptor_HSurface) mySurface2;
  GeomAbs_SurfaceType mySurfaceType2;
  Standard_Boolean myf2surf1F_sameoriented;
  Standard_Boolean mySurfacesSameOriented;
  Standard_Boolean myFacesSameOriented;
  Standard_Real myTol1;
  Standard_Real myTol2;


};







#endif // _TopOpeBRep_Hctxff2d_HeaderFile
