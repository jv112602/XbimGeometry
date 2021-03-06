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

#ifndef _Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d_HeaderFile
#define _Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Extrema_POnCurv2d.hxx>
#include <TCollection_SeqNode.hxx>
#include <TCollection_SeqNodePtr.hxx>
class Extrema_POnCurv2d;
class Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d;


class Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d;
DEFINE_STANDARD_HANDLE(Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d, TCollection_SeqNode)


class Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d : public TCollection_SeqNode
{

public:

  
    Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d(const Extrema_POnCurv2d& I, const TCollection_SeqNodePtr& n, const TCollection_SeqNodePtr& p);
  
    Extrema_POnCurv2d& Value() const;




  DEFINE_STANDARD_RTTI(Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d,TCollection_SeqNode)

protected:




private:


  Extrema_POnCurv2d myValue;


};

#define SeqItem Extrema_POnCurv2d
#define SeqItem_hxx <Extrema_POnCurv2d.hxx>
#define TCollection_SequenceNode Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d
#define TCollection_SequenceNode_hxx <Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d.hxx>
#define Handle_TCollection_SequenceNode Handle(Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d)
#define TCollection_Sequence Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d
#define TCollection_Sequence_hxx <Extrema_SeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d.hxx>

#include <TCollection_SequenceNode.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfELPCOfLocateExtPC2d_HeaderFile
