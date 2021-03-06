// Created on: 1992-10-08
// Created by: Isabelle GRIGNON
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _Adaptor3d_HIsoCurve_HeaderFile
#define _Adaptor3d_HIsoCurve_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Adaptor3d_IsoCurve.hxx>
#include <Adaptor3d_HCurve.hxx>
class Standard_OutOfRange;
class Standard_NoSuchObject;
class Standard_DomainError;
class Adaptor3d_IsoCurve;
class Adaptor3d_Curve;


class Adaptor3d_HIsoCurve;
DEFINE_STANDARD_HANDLE(Adaptor3d_HIsoCurve, Adaptor3d_HCurve)


class Adaptor3d_HIsoCurve : public Adaptor3d_HCurve
{

public:

  
  Standard_EXPORT Adaptor3d_HIsoCurve();
  
  Standard_EXPORT Adaptor3d_HIsoCurve(const Adaptor3d_IsoCurve& C);
  
  Standard_EXPORT void Set (const Adaptor3d_IsoCurve& C);
  
  Standard_EXPORT const Adaptor3d_Curve& Curve() const;
  
  Standard_EXPORT Adaptor3d_Curve& GetCurve();
  
    Adaptor3d_IsoCurve& ChangeCurve();




  DEFINE_STANDARD_RTTI(Adaptor3d_HIsoCurve,Adaptor3d_HCurve)

protected:


  Adaptor3d_IsoCurve myCurve;


private:




};

#define TheCurve Adaptor3d_IsoCurve
#define TheCurve_hxx <Adaptor3d_IsoCurve.hxx>
#define Adaptor3d_GenHCurve Adaptor3d_HIsoCurve
#define Adaptor3d_GenHCurve_hxx <Adaptor3d_HIsoCurve.hxx>
#define Handle_Adaptor3d_GenHCurve Handle(Adaptor3d_HIsoCurve)

#include <Adaptor3d_GenHCurve.lxx>

#undef TheCurve
#undef TheCurve_hxx
#undef Adaptor3d_GenHCurve
#undef Adaptor3d_GenHCurve_hxx
#undef Handle_Adaptor3d_GenHCurve




#endif // _Adaptor3d_HIsoCurve_HeaderFile
