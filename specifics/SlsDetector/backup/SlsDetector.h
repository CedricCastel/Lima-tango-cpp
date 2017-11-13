/*----- PROTECTED REGION ID(SlsDetector.h) ENABLED START -----*/
//=============================================================================
//
// file :        SlsDetector.h
//
// description : Include file for the SlsDetector class
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


#ifndef SlsDetector_H
#define SlsDetector_H

#include <tango.h>

//- YAT/YAT4TANGO
#include <yat4tango/PropertyHelper.h>
#include <yat4tango/DynamicInterfaceManager.h>

#include "Factory.h"

#include "lima/HwInterface.h"
#include "lima/CtControl.h"
#include "lima/CtAcquisition.h"
#include "lima/CtImage.h"

#include "SlsDetectorInterface.h"
#include "SlsDetectorCamera.h"


using namespace yat4tango;

/*----- PROTECTED REGION END -----*/	//	SlsDetector.h

/**
 *  SlsDetector class description:
 *    Device for sls detectors from PSI. 
 */

namespace SlsDetector_ns
{
/*----- PROTECTED REGION ID(SlsDetector::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	SlsDetector::Additional Class Declarations

class SlsDetector : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(SlsDetector::Data Members) ENABLED START -----*/

//	Add your own data members

/*----- PROTECTED REGION END -----*/	//	SlsDetector::Data Members

//	Device property data members
public:
	//	ConfigFname:	Configuration files used during the camera instanciation.
	string	configFname;

//	Attribute data members
public:
	Tango::DevLong	*attr_tresholdEnergy_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	SlsDetector(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	SlsDetector(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	SlsDetector(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */	
	~SlsDetector() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : SlsDetector::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : SlsDetector::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute tresholdEnergy related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_tresholdEnergy(Tango::Attribute &attr);
	virtual void write_tresholdEnergy(Tango::WAttribute &attr);
	virtual bool is_tresholdEnergy_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : SlsDetector::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();



//	Command related methods
public:


/*----- PROTECTED REGION ID(SlsDetector::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
private:
/**
 * This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *	@return	State Code
 *	@exception DevFailed
 */
	Tango::DevState	dev_state();

protected :	
    //lima OBJECTS
    lima::SlsDetector::Interface * m_hw    ;
    lima::CtControl              * m_ct    ;
    lima::SlsDetector::Camera    * m_camera;
	bool                           m_is_device_initialized;
    stringstream                   m_status_message        ;

	yat4tango::DynamicInterfaceManager m_dim;

/*----- PROTECTED REGION END -----*/	//	SlsDetector::Additional Method prototypes
};

/*----- PROTECTED REGION ID(SlsDetector::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	SlsDetector::Additional Classes Definitions

}	//	End of namespace

#endif   //	SlsDetector_H
