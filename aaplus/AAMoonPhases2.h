/*
Module : AAMoonPhases2.h
Purpose: Implementation for the algorithms which obtain the dates for the phases of the Moon (revised version)
Created: PJN / 01-01-2020

Copyright (c) 2020 by PJ Naughter (Web: www.naughter.com, Email: pjna@naughter.com)

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

#ifndef __AAMOONPHASES2_H__
#define __AAMOONPHASES2_H__

#ifndef AAPLUS_EXT_CLASS
#define AAPLUS_EXT_CLASS
#endif //#ifndef AAPLUS_EXT_CLASS


/////////////////////// Includes //////////////////////////////////////////////

#include <vector>


/////////////////////// Classes ///////////////////////////////////////////////

class AAPLUS_EXT_CLASS CAAMoonPhasesDetails2
{
public:
//Enums
  enum class Type
  {
    NotDefined = 0,
    NewMoon = 1,
    FirstQuarter = 2,
    FullMoon = 3,
    LastQuarter = 4
  };

//Constructors / Destructors
  CAAMoonPhasesDetails2() noexcept : type(Type::NotDefined),
                                     JD(0)
  {
  };
  CAAMoonPhasesDetails2(const CAAMoonPhasesDetails2&) = default;
  CAAMoonPhasesDetails2(CAAMoonPhasesDetails2&&) = default;
  ~CAAMoonPhasesDetails2() = default;

//Methods
  CAAMoonPhasesDetails2& operator=(const CAAMoonPhasesDetails2&) = default;
  CAAMoonPhasesDetails2& operator=(CAAMoonPhasesDetails2&&) = default;

//Member variables
  Type type; //The type of the event which has occurred
  double JD; //When the event occurred in TT
};

class AAPLUS_EXT_CLASS CAAMoonPhases2
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
  static std::vector<CAAMoonPhasesDetails2> Calculate(double StartJD, double EndJD, double StepInterval = 0.007, Algorithm algorithm = Algorithm::MeeusTruncated);
};


#endif //#ifndef __AAMOONNODES2_H__
