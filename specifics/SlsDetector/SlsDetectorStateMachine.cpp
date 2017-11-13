/*----- PROTECTED REGION ID(SlsDetectorStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        SlsDetectorStateMachine.cpp
//
// description : State machine file for the SlsDetector class
//
// project :     Sls dectector TANGO specific device.
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <SlsDetector.h>

/*----- PROTECTED REGION END -----*/	//	SlsDetector::SlsDetectorStateMachine.cpp

//================================================================
//  States   |  Description
//================================================================
//  INIT     |  
//  STANDBY  |  
//  FAULT    |  
//  RUNNING  |  


namespace SlsDetector_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : SlsDetector::is_tresholdEnergy_allowed()
 *	Description : Execution allowed for tresholdEnergy attribute
 */
//--------------------------------------------------------
bool SlsDetector::is_tresholdEnergy_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Check access type.
	if ( type!=Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for WRITE 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsDetector::tresholdEnergyStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsDetector::tresholdEnergyStateAllowed_WRITE
			return false;
		}
		return true;
	}
	else

	//	Check access type.
	if ( type==Tango::READ_REQ )
	{
		//	Compare device state with not allowed states for READ 
		if (get_state()==Tango::INIT ||
			get_state()==Tango::FAULT ||
			get_state()==Tango::RUNNING)
		{
		/*----- PROTECTED REGION ID(SlsDetector::tresholdEnergyStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsDetector::tresholdEnergyStateAllowed_READ
			return false;
		}
		return true;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : SlsDetector::is_clockDivider_allowed()
 *	Description : Execution allowed for clockDivider attribute
 */
//--------------------------------------------------------
bool SlsDetector::is_clockDivider_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for clockDivider attribute in Write access.
	/*----- PROTECTED REGION ID(SlsDetector::clockDividerStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsDetector::clockDividerStateAllowed_WRITE

	//	Not any excluded states for clockDivider attribute in read access.
	/*----- PROTECTED REGION ID(SlsDetector::clockDividerStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	SlsDetector::clockDividerStateAllowed_READ
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

}	//	End of namespace
