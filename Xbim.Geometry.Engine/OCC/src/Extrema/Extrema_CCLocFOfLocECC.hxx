// Created on: 1991-02-26
// Created by: Isabelle GRIGNON
// Copyright (c) 1991-1999 Matra Datavision
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

#ifndef _Extrema_CCLocFOfLocECC_HeaderFile
#define _Extrema_CCLocFOfLocECC_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Address.hxx>
#include <Standard_Real.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SeqPOnCOfCCLocFOfLocECC.hxx>
#include <Standard_Integer.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard_Boolean.hxx>
#include <math_Vector.hxx>
class Standard_OutOfRange;
class Adaptor3d_Curve;
class Extrema_CurveTool;
class Extrema_POnCurv;
class gp_Pnt;
class gp_Vec;
class Extrema_SeqPOnCOfCCLocFOfLocECC;
class Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC;
class math_Matrix;



class Extrema_CCLocFOfLocECC  : public math_FunctionSetWithDerivatives
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Extrema_CCLocFOfLocECC(const Standard_Real thetol = 1.0e-10);
  
  Standard_EXPORT Extrema_CCLocFOfLocECC(const Adaptor3d_Curve& C1, const Adaptor3d_Curve& C2, const Standard_Real thetol = 1.0e-10);
  
  Standard_EXPORT void SetCurve (const Standard_Integer theRank, const Adaptor3d_Curve& C1);
  
    void SetTolerance (const Standard_Real theTol);
  
    virtual Standard_Integer NbVariables() const Standard_OVERRIDE;
  
    virtual Standard_Integer NbEquations() const Standard_OVERRIDE;
  
  Standard_EXPORT virtual Standard_Boolean Value (const math_Vector& UV, math_Vector& F) Standard_OVERRIDE;
  
  Standard_EXPORT Standard_Boolean Derivatives (const math_Vector& UV, math_Matrix& DF);
  
  Standard_EXPORT Standard_Boolean Values (const math_Vector& UV, math_Vector& F, math_Matrix& DF);
  
  Standard_EXPORT virtual Standard_Integer GetStateNumber() Standard_OVERRIDE;
  
    Standard_Integer NbExt() const;
  
    Standard_Real SquareDistance (const Standard_Integer N) const;
  
  Standard_EXPORT void Points (const Standard_Integer N, Extrema_POnCurv& P1, Extrema_POnCurv& P2) const;
  
    Standard_Address CurvePtr (const Standard_Integer theRank) const;
  
    Standard_Real Tolerance() const;
  
  Standard_EXPORT void SubIntervalInitialize (const math_Vector& theUfirst, const math_Vector& theUlast);
  
  Standard_EXPORT Standard_Real SearchOfTolerance (const Standard_Address C);




protected:





private:



  Standard_Address myC1;
  Standard_Address myC2;
  Standard_Real myTol;
  Standard_Real myU;
  Standard_Real myV;
  gp_Pnt myP1;
  gp_Pnt myP2;
  gp_Vec myDu;
  gp_Vec myDv;
  TColStd_SequenceOfReal mySqDist;
  Extrema_SeqPOnCOfCCLocFOfLocECC myPoints;
  Standard_Real myTolC1;
  Standard_Real myTolC2;
  Standard_Integer myMaxDerivOrderC1;
  Standard_Integer myMaxDerivOrderC2;
  Standard_Real myUinfium;
  Standard_Real myUsupremum;
  Standard_Real myVinfium;
  Standard_Real myVsupremum;


};

#define Curve1 Adaptor3d_Curve
#define Curve1_hxx <Adaptor3d_Curve.hxx>
#define Tool1 Extrema_CurveTool
#define Tool1_hxx <Extrema_CurveTool.hxx>
#define Curve2 Adaptor3d_Curve
#define Curve2_hxx <Adaptor3d_Curve.hxx>
#define Tool2 Extrema_CurveTool
#define Tool2_hxx <Extrema_CurveTool.hxx>
#define POnC Extrema_POnCurv
#define POnC_hxx <Extrema_POnCurv.hxx>
#define Pnt gp_Pnt
#define Pnt_hxx <gp_Pnt.hxx>
#define Vec gp_Vec
#define Vec_hxx <gp_Vec.hxx>
#define Extrema_SeqPOnC Extrema_SeqPOnCOfCCLocFOfLocECC
#define Extrema_SeqPOnC_hxx <Extrema_SeqPOnCOfCCLocFOfLocECC.hxx>
#define Extrema_SequenceNodeOfSeqPOnC Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC
#define Extrema_SequenceNodeOfSeqPOnC_hxx <Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC.hxx>
#define Extrema_SequenceNodeOfSeqPOnC Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC
#define Extrema_SequenceNodeOfSeqPOnC_hxx <Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC.hxx>
#define Handle_Extrema_SequenceNodeOfSeqPOnC Handle(Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC)
#define Handle_Extrema_SequenceNodeOfSeqPOnC Handle(Extrema_SequenceNodeOfSeqPOnCOfCCLocFOfLocECC)
#define Extrema_FuncExtCC Extrema_CCLocFOfLocECC
#define Extrema_FuncExtCC_hxx <Extrema_CCLocFOfLocECC.hxx>

#include <Extrema_FuncExtCC.lxx>

#undef Curve1
#undef Curve1_hxx
#undef Tool1
#undef Tool1_hxx
#undef Curve2
#undef Curve2_hxx
#undef Tool2
#undef Tool2_hxx
#undef POnC
#undef POnC_hxx
#undef Pnt
#undef Pnt_hxx
#undef Vec
#undef Vec_hxx
#undef Extrema_SeqPOnC
#undef Extrema_SeqPOnC_hxx
#undef Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_SequenceNodeOfSeqPOnC_hxx
#undef Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_SequenceNodeOfSeqPOnC_hxx
#undef Handle_Extrema_SequenceNodeOfSeqPOnC
#undef Handle_Extrema_SequenceNodeOfSeqPOnC
#undef Extrema_FuncExtCC
#undef Extrema_FuncExtCC_hxx




#endif // _Extrema_CCLocFOfLocECC_HeaderFile
