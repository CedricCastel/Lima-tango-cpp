//=============================================================================
//
// file :         AndorCCDClass.h
//
// description :  Include for the AndorCCDClass root class.
//                This class is the singleton class for
//                the AndorCCD device class.
//                It contains all properties and methods which the 
//                AndorCCD requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _ANDORCCDCLASS_H
#define _ANDORCCDCLASS_H

#ifdef WIN32
#include "tango.h"
#endif
#include <AndorCCD.h>

#ifndef WIN32
#include "tango.h"
#endif

namespace AndorCCD_ns
{//=====================================
//	Define classes for attributes
//=====================================
class currentRateAttrib: public Tango::Attr
{
public:
	currentRateAttrib():Attr("currentRate", Tango::DEV_STRING, Tango::READ) {};
	~currentRateAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AndorCCD *>(dev))->read_currentRate(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AndorCCD *>(dev))->is_currentRate_allowed(ty);}
};

class adcModeAttrib: public Tango::Attr
{
public:
	adcModeAttrib():Attr("adcMode", Tango::DEV_ULONG, Tango::READ_WRITE) {};
	~adcModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AndorCCD *>(dev))->read_adcMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AndorCCD *>(dev))->write_adcMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AndorCCD *>(dev))->is_adcMode_allowed(ty);}
};

class temperatureAttrib: public Tango::Attr
{
public:
	temperatureAttrib():Attr("temperature", Tango::DEV_LONG, Tango::READ) {};
	~temperatureAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AndorCCD *>(dev))->read_temperature(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AndorCCD *>(dev))->is_temperature_allowed(ty);}
};

class temperatureTargetAttrib: public Tango::Attr
{
public:
	temperatureTargetAttrib():Attr("temperatureTarget", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~temperatureTargetAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AndorCCD *>(dev))->read_temperatureTarget(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AndorCCD *>(dev))->write_temperatureTarget(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AndorCCD *>(dev))->is_temperatureTarget_allowed(ty);}
};

class currentCoolingStatusAttrib: public Tango::Attr
{
public:
	currentCoolingStatusAttrib():Attr("currentCoolingStatus", Tango::DEV_STRING, Tango::READ) {};
	~currentCoolingStatusAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AndorCCD *>(dev))->read_currentCoolingStatus(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AndorCCD *>(dev))->is_currentCoolingStatus_allowed(ty);}
};

class enabledCoolerAttrib: public Tango::Attr
{
public:
	enabledCoolerAttrib():Attr("enabledCooler", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~enabledCoolerAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AndorCCD *>(dev))->read_enabledCooler(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AndorCCD *>(dev))->write_enabledCooler(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AndorCCD *>(dev))->is_enabledCooler_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
//
// The AndorCCDClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	AndorCCDClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static AndorCCDClass *init(const char *);
	static AndorCCDClass *instance();
	~AndorCCDClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	AndorCCDClass(string &);
	static AndorCCDClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace AndorCCD_ns

#endif // _ANDORCCDCLASS_H
