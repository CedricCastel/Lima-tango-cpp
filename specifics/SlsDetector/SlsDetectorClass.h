/*----- PROTECTED REGION ID(SlsDetectorClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        SlsDetectorClass.h
//
// description : Include for the SlsDetector root class.
//               This class is the singleton class for
//                the SlsDetector device class.
//               It contains all properties and methods which the 
//               SlsDetector requires only once e.g. the commands.
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


#ifndef SlsDetectorClass_H
#define SlsDetectorClass_H

#include <tango.h>
#include <SlsDetector.h>


/*----- PROTECTED REGION END -----*/	//	SlsDetectorClass.h


namespace SlsDetector_ns
{
/*----- PROTECTED REGION ID(SlsDetectorClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	SlsDetectorClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute thresholdEnergy class definition
class thresholdEnergyAttrib: public Tango::Attr
{
public:
	thresholdEnergyAttrib():Attr("thresholdEnergy",
			Tango::DEV_LONG, Tango::READ_WRITE) {};
	~thresholdEnergyAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_thresholdEnergy(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<SlsDetector *>(dev))->write_thresholdEnergy(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_thresholdEnergy_allowed(ty);}
};

//	Attribute clockDivider class definition
class clockDividerAttrib: public Tango::Attr
{
public:
	clockDividerAttrib():Attr("clockDivider",
			Tango::DEV_STRING, Tango::READ_WRITE) {};
	~clockDividerAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_clockDivider(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<SlsDetector *>(dev))->write_clockDivider(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_clockDivider_allowed(ty);}
};

//	Attribute configFileName class definition
class configFileNameAttrib: public Tango::Attr
{
public:
	configFileNameAttrib():Attr("configFileName",
			Tango::DEV_STRING, Tango::READ) {};
	~configFileNameAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_configFileName(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_configFileName_allowed(ty);}
};

//	Attribute rawMode class definition
class rawModeAttrib: public Tango::Attr
{
public:
	rawModeAttrib():Attr("rawMode",
			Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~rawModeAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_rawMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<SlsDetector *>(dev))->write_rawMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_rawMode_allowed(ty);}
};

//	Attribute readoutFlags class definition
class readoutFlagsAttrib: public Tango::Attr
{
public:
	readoutFlagsAttrib():Attr("readoutFlags",
			Tango::DEV_STRING, Tango::READ_WRITE) {};
	~readoutFlagsAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_readoutFlags(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<SlsDetector *>(dev))->write_readoutFlags(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_readoutFlags_allowed(ty);}
};

//	Attribute tolerateLostPackets class definition
class tolerateLostPacketsAttrib: public Tango::Attr
{
public:
	tolerateLostPacketsAttrib():Attr("tolerateLostPackets",
			Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~tolerateLostPacketsAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_tolerateLostPackets(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<SlsDetector *>(dev))->write_tolerateLostPackets(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_tolerateLostPackets_allowed(ty);}
};

//	Attribute nbBadFrames class definition
class nbBadFramesAttrib: public Tango::Attr
{
public:
	nbBadFramesAttrib():Attr("nbBadFrames",
			Tango::DEV_LONG, Tango::READ) {};
	~nbBadFramesAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_nbBadFrames(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_nbBadFrames_allowed(ty);}
};

//	Attribute hostnameList class definition
class hostnameListAttrib: public Tango::SpectrumAttr
{
public:
	hostnameListAttrib():SpectrumAttr("hostnameList",
			Tango::DEV_STRING, Tango::READ, 64) {};
	~hostnameListAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_hostnameList(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_hostnameList_allowed(ty);}
};

//	Attribute dacNameList class definition
class dacNameListAttrib: public Tango::SpectrumAttr
{
public:
	dacNameListAttrib():SpectrumAttr("dacNameList",
			Tango::DEV_STRING, Tango::READ, 64) {};
	~dacNameListAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_dacNameList(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_dacNameList_allowed(ty);}
};

//	Attribute dacNameListMv class definition
class dacNameListMvAttrib: public Tango::SpectrumAttr
{
public:
	dacNameListMvAttrib():SpectrumAttr("dacNameListMv",
			Tango::DEV_STRING, Tango::READ, 64) {};
	~dacNameListMvAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_dacNameListMv(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_dacNameListMv_allowed(ty);}
};

//	Attribute adcNameList class definition
class adcNameListAttrib: public Tango::SpectrumAttr
{
public:
	adcNameListAttrib():SpectrumAttr("adcNameList",
			Tango::DEV_STRING, Tango::READ, 64) {};
	~adcNameListAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_adcNameList(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_adcNameList_allowed(ty);}
};

//	Attribute allTrimBits class definition
class allTrimBitsAttrib: public Tango::SpectrumAttr
{
public:
	allTrimBitsAttrib():SpectrumAttr("allTrimBits",
			Tango::DEV_LONG, Tango::READ_WRITE, 64) {};
	~allTrimBitsAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_allTrimBits(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<SlsDetector *>(dev))->write_allTrimBits(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_allTrimBits_allowed(ty);}
};

//	Attribute badFrameList class definition
class badFrameListAttrib: public Tango::SpectrumAttr
{
public:
	badFrameListAttrib():SpectrumAttr("badFrameList",
			Tango::DEV_LONG, Tango::READ, 100000) {};
	~badFrameListAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<SlsDetector *>(dev))->read_badFrameList(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<SlsDetector *>(dev))->is_badFrameList_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command SetCmd class definition
class SetCmdClass : public Tango::Command
{
public:
	SetCmdClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetCmdClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetCmdClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<SlsDetector *>(dev))->is_SetCmd_allowed(any);}
};

//	Command GetCmd class definition
class GetCmdClass : public Tango::Command
{
public:
	GetCmdClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetCmdClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetCmdClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<SlsDetector *>(dev))->is_GetCmd_allowed(any);}
};


/**
 *	The SlsDetectorClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  SlsDetectorClass : public Tango::DeviceClass
#else
class SlsDetectorClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(SlsDetectorClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	SlsDetectorClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static SlsDetectorClass *init(const char *);
		static SlsDetectorClass *instance();
		~SlsDetectorClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		SlsDetectorClass(string &);
		static SlsDetectorClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	SlsDetector_H