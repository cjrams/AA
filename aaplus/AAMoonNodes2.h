/*
Module : AAMoonNodes2.h
Purpose: Implementation for the algorithms which obtain the dates when the Moon passes thro its nodes (revised version)
Created: PJN / 16-11-2019

Copyright (c) 2019 by PJ Naughter (Web: www.naughter.com, Email: pjna@naughter.com)

All rights reserved.

Copyright / Usage Details:

You are allowed to include the source code in any product (commercial, shareware, freeware or otherwise) 
when your product is released in binary form. You are allowed to modify the source code in any way you want 
except you cannot modify the copyright details at the top of each module. If you want to distribute source 
code with your application, then you are only allowed to distribute versions released by the author. This is 
to maintain a single distribution point for the source code.

*/


/////////////////////// Macros / Defines //////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif //#if _MSC_VER > 1000

#ifndef __AAMOONNODES2_H__
#define __AAMOONNODES2_H__

#ifndef AAPLUS_EXT_CLASS
#define AAPLUS_EXT_CLASS
#endif //#ifndef AAPLUS_EXT_CLASS


/////////////////////// Includes //////////////////////////////////////////////

#include <vector>


/////////////////////// Classes ///////////////////////////////////////////////

class AAPLUS_EXT_CLASS CAAMoonNodesDetails2
{
public:
//Enums
  enum class Type
  {
    NotDefined = 0,
    Ascending = 1,
    Descending = 2
  };

//Constructors / Destructors
  CAAMoonNodesDetails2() noexcept : type(Type::NotDefined),
                                    JD(0)
  {
  };
  CAAMoonNodesDetails2(const CAAMoonNodesDetails2&) = default;
  CAAMoonNodesDetails2(CAAMoonNodesDetails2&&) = default;
  ~CAAMoonNodesDetails2() = default;

//Methods
  CAAMoonNodesDetails2& operator=(const CAAMoonNodesDetails2&) = default;
  CAAMoonNodesDetails2& operator=(CAAMoonNodesDetails2&&) = default;

//Member variables
  Type type; //The type of the event which has occurred
  double JD; //When the event occurred in TT
};

class AAPLUS_EXT_CLASS CAAMoonNodes2
{
public:
//Enums
  enum class Algorithm
  {
    MeeusTruncated = 0
#ifndef AAPLUS_ELP2000_NO_HIGH_PRECISION
    ,
    ELP2000 = 1
#endif //#ifndef AAPLUS_ELP2000_NO_HIGH_PRECISION
#ifndef AAPLUS_ELP2000_NO_HIGH_PRECISION
    ,
    ELPMPP02Nominal = 2,
    ELPMPP02LLR = 3,
    ELPMPP02DE405 = 4,
    ELPMPP02DE406 = 5
#endif //#ifndef AAPLUS_ELP2000_NO_HIGH_PRECISION
  };

//Static methods
  static std::vector<CAAMoonNodesDetails2> Calculate(double StartJD, double EndJD, double StepInterval = 0.007, Algorithm algorithm = Algorithm::MeeusTruncated);
};


#endif //#ifndef __AAMOONNODES2_H__
