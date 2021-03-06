// Copyright (c) 2014 OPEN CASCADE SAS
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

#ifndef _BSplCLib_Cache_Headerfile
#define _BSplCLib_Cache_Headerfile

#include <Standard.hxx>
#include <Standard_Macro.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>


#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>

#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>

#ifndef NOWEIGHTS_CURVE
#define NOWEIGHTS_CURVE (*((TColStd_Array1OfReal*) NULL))
#endif

//! \brief A cache class for B-spline curves.
//!
//! Defines all data, that can be cached on a span of B-spline curve.
//! The data should be recalculated in going from span to span.
class BSplCLib_Cache : public Standard_Transient
{
public:
  //! Default constructor
  Standard_EXPORT BSplCLib_Cache();
  //! Constructor for caching of 2D curves
  //! \param theDegree     degree of the B-spline
  //! \param thePeriodic   identify the B-spline is periodic
  //! \param theFlatKnots  knots of B-spline curve (with repetitions)
  //! \param thePoles2d    array of poles of 2D B-spline
  //! \param theWeights    array of weights of corresponding poles
  Standard_EXPORT BSplCLib_Cache(const Standard_Integer&        theDegree,
                                 const Standard_Boolean&        thePeriodic,
                                 const TColStd_Array1OfReal&    theFlatKnots,
                                 const TColgp_Array1OfPnt2d&    thePoles2d,
                                 const TColStd_Array1OfReal&    theWeights = NOWEIGHTS_CURVE);
  //! Constructor for caching of 3D curves
  //! \param theDegree     degree of the B-spline
  //! \param thePeriodic   identify the B-spline is periodic
  //! \param theFlatKnots  knots of B-spline curve (with repetitions)
  //! \param thePoles      array of poles of 3D B-spline
  //! \param theWeights    array of weights of corresponding poles
  Standard_EXPORT BSplCLib_Cache(const Standard_Integer&        theDegree,
                                 const Standard_Boolean&        thePeriodic,
                                 const TColStd_Array1OfReal&    theFlatKnots,
                                 const TColgp_Array1OfPnt&      thePoles,
                                 const TColStd_Array1OfReal&    theWeights = NOWEIGHTS_CURVE);

  //! Verifies validity of the cache using flat parameter of the point
  //! \param theParameter parameter of the point placed in the span
  Standard_EXPORT Standard_Boolean IsCacheValid(Standard_Real theParameter) const;

  //! Recomputes the cache data for 2D curves. Does not verify validity of the cache
  //! \param theParameter  the value on the knot's axis to identify the span
  //! \param theDegree     degree of the B-spline
  //! \param thePeriodic   identify the B-spline is periodic
  //! \param theFlatKnots  knots of B-spline curve (with repetitions)
  //! \param thePoles2d    array of poles of 2D B-spline
  //! \param theWeights    array of weights of corresponding poles
  Standard_EXPORT void BuildCache(const Standard_Real&           theParameter,
                                  const Standard_Integer&        theDegree,
                                  const Standard_Boolean&        thePeriodic,
                                  const TColStd_Array1OfReal&    theFlatKnots,
                                  const TColgp_Array1OfPnt2d&    thePoles2d,
                                  const TColStd_Array1OfReal&    theWeights = NOWEIGHTS_CURVE);
  //! Recomputes the cache data for 3D curves. Does not verify validity of the cache
  //! \param theParameter  the value on the knot's axis to identify the span
  //! \param theDegree     degree of the B-spline
  //! \param thePeriodic   identify the B-spline is periodic
  //! \param theFlatKnots  knots of B-spline curve (with repetitions)
  //! \param thePoles      array of poles of 3D B-spline
  //! \param theWeights    array of weights of corresponding poles
  Standard_EXPORT void BuildCache(const Standard_Real&           theParameter,
                                  const Standard_Integer&        theDegree,
                                  const Standard_Boolean&        thePeriodic,
                                  const TColStd_Array1OfReal&    theFlatKnots,
                                  const TColgp_Array1OfPnt&      thePoles,
                                  const TColStd_Array1OfReal&    theWeights = NOWEIGHTS_CURVE);

  //! Calculates the point on B-spline in the selected point
  //! \param[in]  theParameter parameter of calculation of the value
  //! \param[out] thePoint     the result of calculation (the point on B-spline)
  Standard_EXPORT void D0(const Standard_Real& theParameter, gp_Pnt2d& thePoint) const;
  Standard_EXPORT void D0(const Standard_Real& theParameter, gp_Pnt&   thePoint) const;

  //! Calculates the point on B-spline and its first derivative in the selected point
  //! \param[in]  theParameter parameter of calculation of the value
  //! \param[out] thePoint     the result of calculation (the point on B-spline)
  //! \param[out] theTangent   tangent vector (first derivatives) for B-spline in the calculated point
  Standard_EXPORT void D1(const Standard_Real& theParameter, gp_Pnt2d& thePoint, gp_Vec2d& theTangent) const;
  Standard_EXPORT void D1(const Standard_Real& theParameter, gp_Pnt&   thePoint, gp_Vec&   theTangent) const;

  //! Calculates the point on B-spline and two derivatives in the selected point
  //! \param[in]  theParameter parameter of calculation of the value
  //! \param[out] thePoint     the result of calculation (the point on B-spline)
  //! \param[out] theTangent   tangent vector (1st derivatives) for B-spline in the calculated point
  //! \param[out] theCurvature curvature vector (2nd derivatives) for B-spline in the calculated point
  Standard_EXPORT void D2(const Standard_Real& theParameter, 
                                gp_Pnt2d&      thePoint, 
                                gp_Vec2d&      theTangent, 
                                gp_Vec2d&      theCurvature) const;
  Standard_EXPORT void D2(const Standard_Real& theParameter, 
                                gp_Pnt&        thePoint, 
                                gp_Vec&        theTangent, 
                                gp_Vec&        theCurvature) const;

  //! Calculates the point on B-spline and three derivatives in the selected point
  //! \param[in]  theParameter parameter of calculation of the value
  //! \param[out] thePoint     the result of calculation (the point on B-spline)
  //! \param[out] theTangent   tangent vector (1st derivatives) for B-spline in the calculated point
  //! \param[out] theCurvature curvature vector (2nd derivatives) for B-spline in the calculated point
  //! \param[out] theTorsion   second curvature vector (3rd derivatives) for B-spline in the calculated point
  Standard_EXPORT void D3(const Standard_Real& theParameter, 
                                gp_Pnt2d&      thePoint, 
                                gp_Vec2d&      theTangent, 
                                gp_Vec2d&      theCurvature,
                                gp_Vec2d&      theTorsion) const;
  Standard_EXPORT void D3(const Standard_Real& theParameter, 
                                gp_Pnt&        thePoint, 
                                gp_Vec&        theTangent, 
                                gp_Vec&        theCurvature,
                                gp_Vec&        theTorsion) const;


  DEFINE_STANDARD_RTTI(BSplCLib_Cache, Standard_Transient)

protected:
  //! Normalizes the parameter for periodical B-splines
  //! \param theFlatKnots knots with repetitions
  //! \param theParameter the value to be normalized into the knots array
  void PeriodicNormalization(const TColStd_Array1OfReal& theFlatKnots, Standard_Real& theParameter) const;

  //! Fills array of derivatives in the selected point of the B-spline
  //! \param[in]  theParameter  parameter of the calculation
  //! \param[in]  theDerivative maximal derivative to be calculated (computes all derivatives lesser than specified)
  //! \param[out] theDerivArray result array of derivatives (with size (theDerivative+1)*(PntDim+1), 
  //!                           where PntDim = 2 or 3 is a dimension of B-spline curve)
  void CalculateDerivative(const Standard_Real&    theParameter, 
                           const Standard_Integer& theDerivative, 
                                 Standard_Real&    theDerivArray) const;

private:
  Handle(TColStd_HArray2OfReal) myPolesWeights; ///< array of poles and weights of calculated cache
                                                // the array has following structure:
                                                //       x1 y1 [z1] [w1]
                                                //       x2 y2 [z2] [w2] etc
                                                // for 2D-curves there is no z conponent, for non-rational curves there is no weight

  Standard_Boolean              myIsRational; ///< identifies the rationality of B-spline
  Standard_Real                 mySpanStart;  ///< parameter for the first point of the span
  Standard_Real                 mySpanLength; ///< length of the span
  Standard_Integer              mySpanIndex;  ///< index of the span on B-spline curve
  Standard_Integer              mySpanIndexMax; ///< maximal number of spans on B-spline curve
  Standard_Integer              myDegree;     ///< degree of B-spline
  Handle(TColStd_HArray1OfReal) myFlatKnots;  ///< knots of B-spline (used for periodic normalization of parameters, exists only for periodical splines)
};

DEFINE_STANDARD_HANDLE(BSplCLib_Cache, Standard_Transient)

#endif
