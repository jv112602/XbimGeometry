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

#ifndef _Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC_HeaderFile
#define _Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TCollection_BaseSequence.hxx>
#include <Standard_Integer.hxx>
class Standard_NoSuchObject;
class Standard_OutOfRange;
class Extrema_POnCurv;
class Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC;



class Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC  : public TCollection_BaseSequence
{
public:

  DEFINE_STANDARD_ALLOC

  
    Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC();
  
  Standard_EXPORT Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC(const Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& Other);
  
  Standard_EXPORT void Clear();
~Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC()
{
  Clear();
}
  
  Standard_EXPORT const Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& Assign (const Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& Other);
const Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& operator = (const Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& Other)
{
  return Assign(Other);
}
  
  Standard_EXPORT void Append (const Extrema_POnCurv& T);
  
    void Append (Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& S);
  
  Standard_EXPORT void Prepend (const Extrema_POnCurv& T);
  
    void Prepend (Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& S);
  
    void InsertBefore (const Standard_Integer Index, const Extrema_POnCurv& T);
  
    void InsertBefore (const Standard_Integer Index, Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& S);
  
  Standard_EXPORT void InsertAfter (const Standard_Integer Index, const Extrema_POnCurv& T);
  
    void InsertAfter (const Standard_Integer Index, Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& S);
  
  Standard_EXPORT const Extrema_POnCurv& First() const;
  
  Standard_EXPORT const Extrema_POnCurv& Last() const;
  
    void Split (const Standard_Integer Index, Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC& Sub);
  
  Standard_EXPORT const Extrema_POnCurv& Value (const Standard_Integer Index) const;
const Extrema_POnCurv& operator() (const Standard_Integer Index) const
{
  return Value(Index);
}
  
  Standard_EXPORT void SetValue (const Standard_Integer Index, const Extrema_POnCurv& I);
  
  Standard_EXPORT Extrema_POnCurv& ChangeValue (const Standard_Integer Index);
Extrema_POnCurv& operator() (const Standard_Integer Index)
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT void Remove (const Standard_Integer Index);
  
  Standard_EXPORT void Remove (const Standard_Integer FromIndex, const Standard_Integer ToIndex);




protected:





private:





};

#define SeqItem Extrema_POnCurv
#define SeqItem_hxx <Extrema_POnCurv.hxx>
#define TCollection_SequenceNode Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC
#define TCollection_SequenceNode_hxx <Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC.hxx>
#define Handle_TCollection_SequenceNode Handle(Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC)
#define TCollection_Sequence Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC
#define TCollection_Sequence_hxx <Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC.hxx>

#include <TCollection_Sequence.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC_HeaderFile
