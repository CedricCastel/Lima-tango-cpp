static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :         Xspress3.cpp
//
// description :  C++ source for the Xspress3 and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                Xspress3 are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
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
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//               BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name|  Method name
//	----------------------------------------
//  State   |  dev_state()
//  Status  |  dev_status()
//
//===================================================================


#include <tango.h>
#include <PogoHelper.h>
#include <iomanip>      
#include <Xspress3.h>
#include <Xspress3Class.h>

namespace Xspress3_ns
{

//+----------------------------------------------------------------------------
//
// method : 		Xspress3::Xspress3(string &s)
// 
// description : 	constructor for simulated Xspress3
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
Xspress3::Xspress3(Tango::DeviceClass *cl,string &s)
:Tango::Device_4Impl(cl,s.c_str()),
m_dim(this)
{
	init_device();
}

Xspress3::Xspress3(Tango::DeviceClass *cl,const char *s)
:Tango::Device_4Impl(cl,s),
m_dim(this) 
{
	init_device();
}

Xspress3::Xspress3(Tango::DeviceClass *cl,const char *s,const char *d)
:Tango::Device_4Impl(cl,s,d),
 m_dim(this)
{
	init_device();
}
//+----------------------------------------------------------------------------
//
// method : 		Xspress3::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void Xspress3::delete_device()
{
	//	Delete device allocated objects
	DELETE_SCALAR_ATTRIBUTE(attr_revision_read);	
	
	//clear user data of dyn attributes
	for(unsigned i = 0;i<m_dyn_total_count.size();i++)
	{
		delete m_dyn_total_count[i];
	}
	m_dyn_total_count.clear();

	for(unsigned i = 0;i<m_dyn_total_processed_count.size();i++)
	{
		delete m_dyn_total_processed_count[i];
	}
	m_dyn_total_processed_count.clear();	

	for(unsigned i = 0;i<m_dyn_icr.size();i++)
	{
		delete m_dyn_icr[i];
	}
	m_dyn_icr.clear();

	for(unsigned i = 0;i<m_dyn_ocr.size();i++)
	{
		delete m_dyn_ocr[i];
	}
	m_dyn_ocr.clear();

	for(unsigned i = 0;i<m_dyn_deadtime.size();i++)
	{
		delete m_dyn_deadtime[i];
	}
	m_dyn_deadtime.clear();
	
	for(unsigned i = 0;i<m_dyn_pileup.size();i++)
	{
		delete m_dyn_pileup[i];
	}
	m_dyn_pileup.clear();
	
	for(unsigned i = 0;i<m_dyn_realtime.size();i++)
	{
		delete m_dyn_realtime[i];
	}
	m_dyn_realtime.clear();	

	for(unsigned i = 0;i<m_dyn_channel.size();i++)
	{
		delete m_dyn_channel[i];
	}
	m_dyn_channel.clear();

    INFO_STREAM << "Remove the inner-appender." << endl;
    yat4tango::InnerAppender::release(this);
}

//+----------------------------------------------------------------------------
//
// method : 		Xspress3::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void Xspress3::init_device()
{
	INFO_STREAM << "Xspress3::Xspress3() create device " << device_name << endl;

	// Initialise variables to default values	
	//--------------------------------------------
	get_device_property();
	
	CREATE_DEVSTRING_ATTRIBUTE(attr_revision_read,MAX_ATTRIBUTE_STRING_LENGTH);
	
    //By default INIT, need to ensure that all objets are OK before set the device to STANDBY
    set_state(Tango::INIT);
    m_is_device_initialized = false;
    m_status_message.str("");

	INFO_STREAM << "Create the inner-appender in order to manage logs." << endl;  
    yat4tango::InnerAppender::initialize(this, 512);

    try
    {
        //- get the main object used to pilot the lima framework
        //in fact LimaDetector is create the singleton control objet
        //so this call, will only return existing object, no need to give it the ip !!
        m_ct = ControlFactory::instance().get_control("Xspress3");
		
        //- get interface to specific camera
        m_hw = dynamic_cast<lima::Xspress3::Interface*> (m_ct->hwInterface());
		
        //- get camera to specific detector
        m_camera = &(m_hw->getCamera());
		
		init_dyn_attributes();
    }
	catch (Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		m_status_message << "Initialization Failed : " << string(df.errors[0].desc) << endl;
		m_is_device_initialized = false;
		set_state(Tango::FAULT);
		return;
	}
    catch (Exception& e)
    {
        ERROR_STREAM << "Initialization Failed : " << e.getErrMsg() << endl;
        m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
        m_is_device_initialized = false;
        set_state(Tango::FAULT);
        return;
    }		
    catch (...)
    {
        ERROR_STREAM << "Initialization Failed : UNKNOWN" << endl;
        m_status_message << "Initialization Failed : UNKNOWN" << endl;
        set_state(Tango::FAULT);
        m_is_device_initialized = false;
        return;
    }
    m_is_device_initialized = true;
    set_state(Tango::STANDBY);
    dev_state();	
}


//+----------------------------------------------------------------------------
//
// method : 		Xspress3::get_device_property()
// 
// description : 	Read the device properties from database.
//
//-----------------------------------------------------------------------------
void Xspress3::get_device_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read device properties from database.(Automatic code generation)
	//------------------------------------------------------------------
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("BaseIPAdress"));
	dev_prop.push_back(Tango::DbDatum("BaseMacAddress"));
	dev_prop.push_back(Tango::DbDatum("BasePort"));
	dev_prop.push_back(Tango::DbDatum("CardIndex"));
	dev_prop.push_back(Tango::DbDatum("DirectoryName"));
	dev_prop.push_back(Tango::DbDatum("MaxFrames"));
	dev_prop.push_back(Tango::DbDatum("NbCards"));
	dev_prop.push_back(Tango::DbDatum("NbChans"));
	dev_prop.push_back(Tango::DbDatum("NoUDP"));

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_device()->get_property(dev_prop);
	Tango::DbDatum	def_prop, cl_prop;
	Xspress3Class	*ds_class =
		(static_cast<Xspress3Class *>(get_device_class()));
	int	i = -1;

	//	Try to initialize BaseIPAdress from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  baseIPAdress;
	else {
		//	Try to initialize BaseIPAdress from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  baseIPAdress;
	}
	//	And try to extract BaseIPAdress value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  baseIPAdress;

	//	Try to initialize BaseMacAddress from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  baseMacAddress;
	else {
		//	Try to initialize BaseMacAddress from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  baseMacAddress;
	}
	//	And try to extract BaseMacAddress value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  baseMacAddress;

	//	Try to initialize BasePort from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  basePort;
	else {
		//	Try to initialize BasePort from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  basePort;
	}
	//	And try to extract BasePort value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  basePort;

	//	Try to initialize CardIndex from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  cardIndex;
	else {
		//	Try to initialize CardIndex from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  cardIndex;
	}
	//	And try to extract CardIndex value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  cardIndex;

	//	Try to initialize DirectoryName from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  directoryName;
	else {
		//	Try to initialize DirectoryName from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  directoryName;
	}
	//	And try to extract DirectoryName value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  directoryName;

	//	Try to initialize MaxFrames from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  maxFrames;
	else {
		//	Try to initialize MaxFrames from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  maxFrames;
	}
	//	And try to extract MaxFrames value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  maxFrames;

	//	Try to initialize NbCards from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  nbCards;
	else {
		//	Try to initialize NbCards from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  nbCards;
	}
	//	And try to extract NbCards value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  nbCards;

	//	Try to initialize NbChans from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  nbChans;
	else {
		//	Try to initialize NbChans from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  nbChans;
	}
	//	And try to extract NbChans value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  nbChans;

	//	Try to initialize NoUDP from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  noUDP;
	else {
		//	Try to initialize NoUDP from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  noUDP;
	}
	//	And try to extract NoUDP value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  noUDP;



	//	End of Automatic code generation
	//------------------------------------------------------------------
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"192.168.0.1","BaseIPAdress");	
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"02.00.00.00.00.00","BaseMacAddress");	
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"30123","BasePort");
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"0","CardIndex");
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"/etc/xspress3/calibration/me4_mar_2018/settings/","DirectoryName");
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"16384","MaxFrames");
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"2","NbCards");
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"4","NbChans");
	yat4tango::PropertyHelper::create_property_if_empty(this, dev_prop,"false","NoUDP");
}
//+----------------------------------------------------------------------------
//
// method : 		Xspress3::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void Xspress3::always_executed_hook()
{
	try
	{
		yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
		m_status_message.str("");
		//- get the singleton control objet used to pilot the lima framework
        m_ct = ControlFactory::instance().get_control("Xspress3");
		
        //- get interface to specific camera
        m_hw = dynamic_cast<lima::Xspress3::Interface*> (m_ct->hwInterface());
		
        //- get camera to specific detector
        m_camera = &(m_hw->getCamera());
		
		dev_state();

	}
	catch (Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		m_status_message << "Initialization Failed : " << e.getErrMsg() << endl;
		//- throw exception
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}
	catch (Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		m_status_message << "Initialization Failed : " << string(df.errors[0].desc) << endl;
		m_is_device_initialized = false;
		set_state(Tango::FAULT);
		return;
	}	
}
//+----------------------------------------------------------------------------
//
// method : 		Xspress3::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void Xspress3::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "Xspress3::read_attr_hardware(vector<long> &attr_list) entering... "<< endl;
	//	Add your own code here		
	////yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
	long my_frame_nb = get_last_image_counter();	
	if(my_frame_nb >0)
	{
		DEBUG_STREAM<<"frame_nb = "<<my_frame_nb-1<<std::endl;
		std::string attr_name;
		int channel_nb;
		//- update attributes	
		for (int i=0; i<attr_list.size();i++)
		{
			//get name of attribute
			attr_name = dev_attr->get_attr_by_ind(attr_list[i]).get_name();	
			DEBUG_STREAM<<"attr_name = "<<attr_name<<std::endl;
			std::istringstream channel_str (attr_name.substr(attr_name.length()-2, attr_name.length()));
			channel_str>>channel_nb;
			DEBUG_STREAM<<"channel_nb = "<<channel_nb<<std::endl;
			//if attributes channel
			if(attr_name.find("channel")!=std::string::npos)
			{
				//- update channel attribute		
				//dyn attribute channel
				//useDtc = true, for readScalers() (seems there is a bug if useDtc = false)
				Data data_histograms;
				m_camera->readHistogram(data_histograms, my_frame_nb-1, channel_nb);		
				std::vector<unsigned int> vec;
				//std::copy((double*)data_histograms.data(), (double*)(data_histograms.data()+(maxFrames/nbChans-1)), back_inserter(vec));
				std::copy(&((unsigned int*)data_histograms.data())[0], &((unsigned int*)data_histograms.data())[maxFrames/nbChans-1], back_inserter(vec));
				m_dyn_channel[channel_nb]->set_value(vec);			
				DEBUG_STREAM<<attr_name<<" - updated"<<std::endl;
			}
			else
			{
				//- update stats of the attribute			
				//dyn attribut stats
				/*************************************
				scaler 0  - Time
				scaler 1  - ResetTicks
				scaler 2  - ResetCount
				scaler 3  - AllEvent
				scaler 4  - AllGood
				scaler 5  - InWindow 0
				scaler 6  - InWindow 1
				scaler 7  - PileUp
				scalar 8  - Total Ticks
				scalar 9  - Deadtime %
				scalar 10 - Deadtime correction factor			
				NB:
				80Mhz => tick = 1/80000000 = 12.5/1E9
				*************************************/			
				//useDtc = false, for readScalers() (seems there is a bug if useDtc = true)				
				Data data_scalers;
				m_camera->readScalers(data_scalers, my_frame_nb-1, channel_nb);	
				DEBUG_STREAM<<"data_scalers["<<0 <<"] = "<<((double*)data_scalers.data())[0 ]<<" - Time"						<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<1 <<"] = "<<((double*)data_scalers.data())[1 ]<<" - ResetTicks"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<2 <<"] = "<<((double*)data_scalers.data())[2 ]<<" - ResetCount"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<3 <<"] = "<<((double*)data_scalers.data())[3 ]<<" - AllEvent"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<4 <<"] = "<<((double*)data_scalers.data())[4 ]<<" - AllGood"						<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<5 <<"] = "<<((double*)data_scalers.data())[5 ]<<" - InWindow 0"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<6 <<"] = "<<((double*)data_scalers.data())[6 ]<<" - InWindow 1"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<7 <<"] = "<<((double*)data_scalers.data())[7 ]<<" - PileUp"						<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<8 <<"] = "<<((double*)data_scalers.data())[8 ]<<" - Total Ticks"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<9 <<"] = "<<((double*)data_scalers.data())[9 ]<<" - Deadtime %"					<<std::endl;
				DEBUG_STREAM<<"data_scalers["<<10<<"] = "<<((double*)data_scalers.data())[10]<<" - Deadtime correction factor"	<<std::endl;	

				m_dyn_total_count[channel_nb]->set_value(((double*)data_scalers.data())[3]);//AllEvent
				m_dyn_total_processed_count[channel_nb]->set_value(((double*)data_scalers.data())[4]);//AllGood    
				m_dyn_icr[channel_nb]->set_value((((double*)data_scalers.data())[3]/(((double*)data_scalers.data())[0]/80000000.0))); //AllEvent/Time *12.5/1E9
				m_dyn_ocr[channel_nb]->set_value((((double*)data_scalers.data())[4]/(((double*)data_scalers.data())[8]/80000000.0)));//AllGood/Time   *12.5/1E9
				m_dyn_deadtime[channel_nb]->set_value(((double*)data_scalers.data())[9]);//Deadtime	
				m_dyn_pileup[channel_nb]->set_value(((double*)data_scalers.data())[7]);//Pileup
				m_dyn_realtime[channel_nb]->set_value(((double*)data_scalers.data())[8]/80000000.0);//TotalTicks * 12.5/1E9
				DEBUG_STREAM<<attr_name<<" - updated"<<std::endl;
			}			
		}
		
	}
}
//+----------------------------------------------------------------------------
//
// method : 		Xspress3::read_revision
// 
// description : 	Extract real attribute values for revision acquisition result.
//
//-----------------------------------------------------------------------------
void Xspress3::read_revision(Tango::Attribute &attr)
{
	DEBUG_STREAM << "Xspress3::read_revision(Tango::Attribute &attr) entering... "<< endl;
	try
    {
		////yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());			
		int revision = 0;
		m_camera->getRevision(revision);
		stringstream ss;
		int major = (revision >> 12) & 0xfff;
		int minor = revision & 0xfff;
		ss << major << "." << minor;	
		strcpy(*attr_revision_read, ss.str().c_str());
        attr.set_value(attr_revision_read);
    }
    catch (Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                                          "TANGO_DEVICE_ERROR",
                                          string(df.errors[0].desc).c_str(),
                                          "Xspress3::read_revision");
    }
    catch (Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        Tango::Except::throw_exception("TANGO_DEVICE_ERROR",
                                       e.getErrMsg().c_str(),
                                       "Xspress3::read_revision");
    }		
}


//+----------------------------------------------------------------------------
//
// method :         LimaDetector::get_last_image_counter
//
//-----------------------------------------------------------------------------
long long Xspress3::get_last_image_counter(void)
{
    DEBUG_STREAM << "LimaDetector::get_last_image_counter()" << endl;
	////yat::AutoMutex<> _lock(ControlFactory::instance().get_global_mutex());
    long long last_image_counter = 0;
    try
    {
		AcqMode mode;
		m_ct->acquisition()->getAcqMode(mode);
        if(mode == Single)
        {
            last_image_counter = m_hw->getNbHwAcquiredFrames();
        }
        else
        {
            m_ct->video()->getLastImageCounter(last_image_counter);
            last_image_counter += 1;
        }
    }
    catch(Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        THROW_DEVFAILED("TANGO_DEVICE_ERROR",
                        e.getErrMsg().c_str(),
                        "Xspress3::get_last_image_counter");
    }
    return last_image_counter;
}

//-----------------------------------------------------------------------------
// method :  Xspress3::init_dyn_attributes()
// description : Create all dynamic attrs
//-----------------------------------------------------------------------------
void Xspress3::init_dyn_attributes()
{
    INFO_STREAM << "Xspress3::init_dyn_attributes() - [BEGIN]" << endl;    
    
    //- remove all previous dyn attributes
    m_dim.dynamic_attributes_manager().remove_attributes();
	
    INFO_STREAM<<"nb. total channels = "<<nbChans<<endl;
    INFO_STREAM<<"nb. bins = "<<maxFrames/nbChans<<endl;

    m_dyn_total_count.resize(nbChans);
	m_dyn_total_processed_count.resize(nbChans);	
    m_dyn_realtime.resize(nbChans);
    m_dyn_deadtime.resize(nbChans);
    m_dyn_icr.resize(nbChans);
    m_dyn_ocr.resize(nbChans);
    m_dyn_pileup.resize(nbChans);
	m_dyn_channel.resize(nbChans);
	
    for(int i = 0; i<nbChans; i++)
    {
        stringstream ss("");
        std::string name("");
        name = "totalCount";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_total_count[i] = new DoubleUserData(ss.str());
        create_attribute(ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         "cts",
                         "%d",
                         "Number of all event triggers = ALLEVENT.",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_total_count[i]);

        ////////////////////////////////////////////////////////////////////////////////////////
        ss.str("");
        name = "totalProcessedCount";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_total_processed_count[i] = new DoubleUserData(ss.str());
        create_attribute(ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         "cts",
                         "%d",
                         "Number of processed event = ALLGOOD.",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_total_processed_count[i]);

        ////////////////////////////////////////////////////////////////////////////////////////
        ss.str("");
        name = "icr";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_icr[i] = new DoubleUserData(ss.str());
        create_attribute(ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         "cts/sec",
                         "%.2f",
                         "Input Count Rate = AllEvent/Time.",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_icr[i]);

        ////////////////////////////////////////////////////////////////////////////////////////
        ss.str("");
        name = "ocr";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_ocr[i] = new DoubleUserData(ss.str());
        create_attribute(ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         "cts/sec",
                         "%.2f",
                         "Output Count Rate = AllGood/Time.",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_ocr[i]);
		
        ////////////////////////////////////////////////////////////////////////////////////////
        ss.str("");
        name = "deadTime";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_deadtime[i] = new DoubleUserData(ss.str());
        create_attribute(ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         "%",
                         "%.2f",
                         "Temps mort = 100*(1-AllGood/AllEvent) ",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_deadtime[i]);
		
        ////////////////////////////////////////////////////////////////////////////////////////
        ss.str("");
        name = "pileup";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_pileup[i] = new DoubleUserData(ss.str());
        create_attribute(ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         " ",
                         "%.2f",
                         "Pileup = 100*PileUp/AllGood.",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_pileup[i]);
		
        ////////////////////////////////////////////////////////////////////////////////////////	
				
        ss.str("");
        name = "realTime";
        ss<<name<<std::setfill('0') << std::setw(2)<<i;
        m_dyn_realtime[i] = new DoubleUserData(ss.str());
        create_attribute(	ss.str(),
                         Tango::DEV_DOUBLE,
                         Tango::SCALAR,
                         Tango::READ,
                         Tango::OPERATOR,
                         "sec",
                         "%.3f",
                         "TotalTicks*12.5/109",
                         &Xspress3::read_stat_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_realtime[i]);
		
        ////////////////////////////////////////////////////////////////////////////////////////
        ss.str("");
		name = "channel";
		ss << name << std::setfill('0') << std::setw(2) << i;
		//- associate the dyn. attr. with its data
		m_dyn_channel[i] = new ChannelUserData(ss.str(), maxFrames/nbChans);
        create_attribute(ss.str(),
                         Tango::DEV_ULONG,
                         Tango::SPECTRUM,
                         Tango::READ,
                         Tango::OPERATOR,
                         "cts",
                         "%d",
                         "Histogram of datas.",
                         &Xspress3::read_channel_callback,
                         &Xspress3::write_callback_null,
                         m_dyn_channel[i],
						 maxFrames/nbChans);		
    }
    INFO_STREAM << "Xspress3::init_common_attributes() - [END]" << endl;
}

//+------------------------------------------------------------------
/**
 *    method:    Xspress3::dev_state
 *
 *    description:    method to execute "State"
 *    This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *
 * @return    State Code
 *
 */
//+------------------------------------------------------------------

Tango::DevState Xspress3::dev_state()
{
    Tango::DevState argout = DeviceImpl::dev_state();
    DEBUG_STREAM << "Xspress3::dev_state(): entering... !" << endl;
    //    Add your own code to control device here
    stringstream DeviceStatus;
    DeviceStatus << "";
    Tango::DevState DeviceState = Tango::STANDBY;
    if (!m_is_device_initialized)
    {
        DeviceState = Tango::FAULT;
        DeviceStatus << m_status_message.str();
    }
    else
    {
        // state & status are retrieved from Factory, Factory is updated by Generic device
        DeviceState = ControlFactory::instance().get_state();
        DeviceStatus << ControlFactory::instance().get_status();
    }

    set_state(DeviceState);
    set_status(DeviceStatus.str());

    argout = DeviceState;
    DEBUG_STREAM << "Xspress3::dev_state() ending... " << endl;
    return argout;
}

//-----------------------------------------------------------------------------
// method :  Xspress3::read_stat_callback()
// description : Read callback fct for statistics dynamic attrs
//-----------------------------------------------------------------------------
void Xspress3::read_stat_callback(yat4tango::DynamicAttributeReadCallbackData& cbd)
{
    DEBUG_STREAM << "Xspress3::read_stat_callback() : "<<cbd.dya->get_name()<<" - [BEGIN]" << endl;
	Tango::DevState state = get_state();
    if ((state == Tango::FAULT && m_is_device_initialized) ||   state == Tango::INIT )
    {
        std::string reason = "It's currently not allowed to read attribute : "+cbd.dya->get_name();
        Tango::Except::throw_exception("TANGO_DEVICE_ERROR",
                                       reason.c_str(),
                                       "Xspress3::read_stat_callback()");
    }

    //- be sure the pointer to the dyn. attr. is valid
    if(!cbd.dya)
    {
        THROW_DEVFAILED("INTERNAL_ERROR",
                        "unexpected NULL pointer to dynamic attribute",
                        "DynamicInterface::read_callback");
    }

    try
    {
        switch(cbd.dya->get_tango_data_type())
        {
            case Tango::DEV_DOUBLE:
            {
                DoubleUserData* user_data = cbd.dya->get_user_data<DoubleUserData>();
                //- set the attribute value
                cbd.tga->set_value((Tango::DevDouble*)&user_data->get_value());
            }
                break;

            case Tango::DEV_LONG:
            {
                LongUserData* user_data = cbd.dya->get_user_data<LongUserData>();
                //- set the attribute value
                cbd.tga->set_value((Tango::DevLong*)&user_data->get_value());
            }
                break;
				
            case Tango::DEV_ULONG:
            {
                ULongUserData* user_data = cbd.dya->get_user_data<ULongUserData>();
                //- set the attribute value
                cbd.tga->set_value((Tango::DevULong*)&user_data->get_value());
            }
                break;
				
        }
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                                          "TANGO_DEVICE_ERROR",
                                          string(df.errors[0].desc).c_str(),
                                          "Xspress3::read_stat_callback");
    }
    DEBUG_STREAM << "Xspress3::read_stat_callback() - [END]" << endl;
}

//-----------------------------------------------------------------------------
// method : Xspress3::read_channel_callback()
// description: read callback fct for the channels spectrum dynamic attrs
//-----------------------------------------------------------------------------
void Xspress3::read_channel_callback(yat4tango::DynamicAttributeReadCallbackData& cbd)
{
	DEBUG_STREAM << "Xspress3::read_channel_callback() : " << cbd.dya->get_name() << " - [BEGIN]" << endl;
	Tango::DevState state = get_state();
	if((state == Tango::FAULT && m_is_device_initialized) ||	state == Tango::INIT )
	{
		std::string reason = "It's currently not allowed to read attribute : " + cbd.dya->get_name();
		Tango::Except::throw_exception("TANGO_DEVICE_ERROR",
									reason.c_str(),
									"Xspress3::read_channel_callback()");
	}

	//- be sure the pointer to the dyn. attr. is valid
	if(!cbd.dya)
	{
		THROW_DEVFAILED("INTERNAL_ERROR",
						"unexpected NULL pointer to dynamic attribute",
						"DynamicInterface::read_callback");
	}

	try
	{
		ChannelUserData* channel_data = cbd.dya->get_user_data<ChannelUserData>();
		//- set the attribute value
		cbd.tga->set_value(const_cast<Tango::DevULong*> (&channel_data->get_value()[0]), channel_data->get_value().size());
	}
	catch(Tango::DevFailed& df)
	{
		ERROR_STREAM << df << endl;
		//- rethrow exception
		Tango::Except::re_throw_exception(df,
										"TANGO_DEVICE_ERROR",
										string(df.errors[0].desc).c_str(),
										"Xspress3::read_channel_callback");
	}
	DEBUG_STREAM << "Xspress3::read_channel_callback() - [END]" << endl;
}



}	//	namespace