//=============================================================================
//
// file :        LimaDetector.h
//
// description : Include for the LimaDetector class.
//
// project :	LimaDetector
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
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//         BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//=============================================================================
//
//          This file is generated by POGO
//    (Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _LimaDetector_H
#define _LimaDetector_H

#include "Factory.h"
//- Tango
#include <tango.h>

//- YAT/YAT4TANGO
#include <yat4tango/PropertyHelper.h>
#include <yat4tango/InnerAppender.h>
#include <yat4tango/DynamicAttributeManager.h>

//- STL 
#include <algorithm>
#include <string>
#include <iostream>

//- LIMA
#include "Debug.h"
#include "HwInterface.h"
#include "CtControl.h"
#include "CtAcquisition.h"
#include "CtAccumulation.h"
#include "CtSaving.h"
#include "CtImage.h"
#include "Data.h"
#include "CtVideo.h"
#include "CtShutter.h"



//- This Device
#include "AcquisitionTask.h"

using namespace lima;
using namespace std;
using namespace yat4tango;

/**
 * @author    $Author:  $
 * @version    $Revision:  $
 */

 //    Add your own constant definitions here.
 //-----------------------------------------------

const size_t MAX_ATTRIBUTE_STRING_LENGTH = 256;
const size_t LOG_BUFFER_DEPTH = 1024;

namespace LimaDetector_ns
{


/**
 * Class Description:
 * Generic device intented to manage Detector via Lima Framework
 */

/*
 *	Device States Description:
*  Tango::INIT :     Error occured at the initialization of the device.<br>
 *                    It is mandatory to fix the errors and run the [ Init ] command of the LimaDetector device.<br>
 *                    The [ Snap ] command IS NOT available.<br>
 *                    The [ Start ] command IS NOT available.<br>
 *                    The [ Stop ] command IS NOT available.<br>
 *                    The [ SetRoi ] command IS NOT available.<br>
 *                    The [ SetBinning ] command IS NOT available.<br>
*  Tango::STANDBY :  The Device is Waiting for a user request.<br>
 *                    The [ Snap ] command IS available.<br>
 *                    The [ Start ] command IS available.<br>
 *                    The [ Stop ] command IS available.<br>
 *                    The [ SetRoi ] command IS available.<br>
 *                    The [ SetBinning ] command IS available.<br>
*  Tango::FAULT :    Acquisition/Settings of the detector encounter a problem.<BR>
 *                    The [ Snap ] command IS available.<br>
 *                    The [ Start ] command IS available.<br>
 *                    The [ Stop ] command IS available.<br>
 *                    The [ SetRoi ] command IS available.<br>
 *                    The [ SetBinning ] command IS available.<br>
*  Tango::RUNNING :  The Acquisition is in Progress.<br>
 *                    The [ Snap ] command IS NOT available.<br>
 *                    The [ Start ] command IS NOT available.<br>
 *                    The [ Stop ] command IS available.<br>
 *                    The [ SetRoi ] command IS NOT available.<br>
 *                    The [ SetBinning ] command IS NOT available.<br>
 */


class LimaDetector: public Tango::Device_4Impl
{
public :
    //    Add your own data members here
    //-----------------------------------------
    
        /* used for dynamic attributes */
		Tango::DevString	*attr_shutterMode_read;    
        Tango::DevString	attr_shutterMode_write;
        Tango::DevString    *attr_shutterState_read;
        Tango::DevDouble    *attr_shutterOpenTime_read;
        Tango::DevDouble    attr_shutterOpenTime_write;
        Tango::DevDouble    *attr_shutterCloseTime_read;
        Tango::DevDouble    attr_shutterCloseTime_write;
        Tango::DevDouble    *attr_exposureAccTime_read;
        Tango::DevDouble    attr_exposureAccTime_write;
        Tango::DevULong    *attr_currentAccFrame_read;
		


    //    Here is the Start of the automatic code generation part
    //-------------------------------------------------------------    
/**
 *    @name attributes
 *    Attribute member data.
 */
//@{
		Tango::DevString	*attr_detectorDescription_read;
		Tango::DevString	*attr_detectorType_read;
		Tango::DevString	*attr_detectorModel_read;
		Tango::DevUShort	*attr_binnedWidthMax_read;
		Tango::DevUShort	*attr_binnedHeightMax_read;
		Tango::DevUShort	*attr_detectorPixelDepth_read;
		Tango::DevString	*attr_triggerMode_read;
		Tango::DevString	attr_triggerMode_write;
		Tango::DevString	*attr_acquisitionMode_read;
		Tango::DevString	attr_acquisitionMode_write;
		Tango::DevDouble	*attr_exposureTime_read;
		Tango::DevDouble	attr_exposureTime_write;
		Tango::DevDouble	*attr_latencyTime_read;
		Tango::DevDouble	attr_latencyTime_write;
		Tango::DevUShort	*attr_roiX_read;
		Tango::DevUShort	*attr_roiY_read;
		Tango::DevUShort	*attr_roiWidth_read;
		Tango::DevUShort	*attr_roiHeight_read;
		Tango::DevUShort	*attr_binningH_read;
		Tango::DevUShort	*attr_binningV_read;
		Tango::DevLong	*attr_nbFrames_read;
		Tango::DevLong	attr_nbFrames_write;
		Tango::DevULong	*attr_currentFrame_read;
		Tango::DevBoolean	*attr_fileGeneration_read;
		Tango::DevBoolean	attr_fileGeneration_write;
		Tango::DevBoolean	*attr_flipX_read;
		Tango::DevBoolean	attr_flipX_write;
		Tango::DevBoolean	*attr_flipY_read;
		Tango::DevBoolean	attr_flipY_write;
//@}

/**
 * @name Device properties
 * Device properties member data.
 */
//@{
/**
 *	Detector user-defined text to identify the engine.
 */
	string	detectorDescription;
/**
 *	Define the type of the connected Detector .<BR>
 *	Availables types :<BR>
 *	- AdscCCD<BR>
 *	- BaslerCCD<BR>
 *	- MarCCD<BR>
 *	- Pco<BR>
 *	- PerkinElmer<BR>
 *	- PilatusPixelDetector<BR>
 *	- ProsilicaCCD<BR>
 *	- PrincetonCCD<BR>
 *	- SimulatorCCD<BR>
 *	- XpadPixelDetector<BR>
 *	
 *	
 */
	string	detectorType;
/**
 *	Define the pixel depth of the detector : <br>
 *	Availables values : <br>
 *	- 8 <br>
 *	- 16<br>
 *	- 32<br>
 */
	Tango::DevUShort	detectorPixelDepth;
/**
 *	Define the format of video stream: <br>
 *	Availables values :<br>
 *	- NONE<BR>
 *	- Y8 <BR>
 *	- Y16<BR>
 *	- Y32<BR>
 *	- Y64<BR>
 *	- RGB555<BR>
 *	- RGB565<BR>
 *	- RGB24<BR>
 *	- RGB32<BR>
 *	- BGR24<BR>
 *	- BGR32<BR>
 *	- BAYER_RG8<BR>
 *	- BAYER_RG16<BR>
 *	- I420<BR>
 *	- YUV411<BR>
 *	- YUV422<BR>
 *	- YUV444<BR>
 *	<br>
 *	Nota:<br>
 *	This property is usefull only for detectors having video capabilities.<BR>
 *	Otherwise, use only NONE.
 */
	string	detectorVideoMode;
/**
 *	Choose the source of Data given to the image attribute :<br>
 *	- VIDEO : use ctVideo->LastImage()
 *	- ACQUISITION : use ctControl->ReadImage()
 */
	string	imageSource;
/**
 *	Define the format of image files :<BR>
 *	Availables values :<br>
 *	- EDF<BR>
 *	- NXS<BR>
 *	- RAW<BR>
 *	
 */
	string	fileFormat;
/**
 *	Define the prefix used for the image files name.
 */
	string	filePrefix;
/**
 *	Define the pattern of the index used for image files names.<br>
 *	<br>
 *	Nota :<br>
 *	%04d mean that file name index will be end with exactly  4 digits filled by '0' if necessary .<br>
 *	
 */
	string	fileIndexPattern;
/**
 *	Define the amount of frames stored in the target file.<br>
 *	If Nexus file, this is the NbAcqPerFile.
 */
	Tango::DevLong	fileNbFrames;
/**
 *	Define the Path where Files will be generated, only when savingFile is checked.
 *	
 *	
 */
	string	fileTargetPath;
/**
 *	Define modules that we need to have some debug traces.<BR>
 *	Availables values :<BR>
 *	- None<BR>
 *	- Hardware<BR>
 *	- Control<BR>
 *	- Common<BR>
 *	- Camera<BR>
 */
	vector<string>	debugModules;
/**
 *	Define Lima verbose level of traces.<BR>
 *	Availables values :<BR>
 *	- Fatal<BR>
 *	- Error<BR>
 *	- Warning<BR>
 *	- Trace<BR>
 *	- Funct<BR>
 *	- Param<BR>
 *	- Return<BR>
 *	- Always<BR>
 */
	vector<string>	debugLevels;
/**
 *	Define Lima traces format.<BR>
 *	Availables values :<BR>
 *	- DateTime<BR>
 *	- Thread<BR>
 *	- Module<BR>
 *	- Obj<BR>
 *	- Funct<BR>
 *	- FileLine<BR>
 */
	vector<string>	debugFormats;
/**
 *	Memorize/Define the Region of Interest of the Acquisition: <br>
 *	origin X<br>
 *	origin Y<br>
 *	Width<br>
 *	Height<br>
 *	<br>
 *	Nota:<br>
 *	if any roi value is <0, then we consider all detector area as Roi.
 */
	vector<short>	memorizedRoi;
/**
 *	Memorize/Define the Binning Horizontal value of the Acquisition<br>
 *	
 */
	Tango::DevUShort	memorizedBinningH;
/**
 *	Memorize/Define the Binning Vertical value of the Acquisition<br>
 */
	Tango::DevUShort	memorizedBinningV;
/**
 *	Memorize/Define the acquisitionMode attribute at Init device<br>
 *	Availables values :<br>
 *	- SINGLE<br>
 *	- ACCUMULATION<br>
 */
	string	memorizedAcquisitionMode;
/**
 *	Memorize/Define the triggerMode attribute at Init device<br>
 *	Availables values :<br>
 *	- INTERNAL_SINGLE<br>
 *	- EXTERNAL_SINGLE<br>
 *	- EXTERNAL_MULTI<br>
 *	- EXTERNAL_GATE<br>
 *	- INTERNAL_MULTI<br>
 *	- EXTERNAL_START_STOP<br>
 *	- EXTERNAL_READOUT<br>
 */
	string	memorizedTriggerMode;
/**
 *	Memorize/Define the shutterMode attribute at Init device<br>
 *	Availables values :<br>
 *	- MANUAL<br>
 *	- AUTO_FRAME<br>
 *	- AUTO_SEQUENCE
 */
	string	memorizedShutterMode;
/**
 *	Memorize/Define the shutterOpenTime attribute at Init device<br>
 */
	Tango::DevDouble	memorizedShutterOpenTime;
/**
 *	Memorize/Define the shutterCloseTime attribute at Init device<br>
 */
	Tango::DevDouble	memorizedShutterCloseTime;
/**
 *	Memorize/Define the exposureTime attribute  at Init device<br>
 *	
 */
	Tango::DevDouble	memorizedExposureTime;
/**
 *	Memorize/Define the exposureAccTime attribute at Init device<br>
 */
	Tango::DevDouble	memorizedExposureAccTime;
/**
 *	Memorize/Define the latencyTime attribute  at Init device<br>
 */
	Tango::DevDouble	memorizedLatencyTime;
/**
 *	Memorize/Define the nbFrames attribute  at Init device<br>
 */
	Tango::DevLong	memorizedNbFrames;
/**
 *	Memorize/Define the fileGeneration attribute at Init device<br>
 */
	Tango::DevBoolean	memorizedFileGeneration;
/**
 *	Memorize/Define the flipX attribute at Init device<br>
 */
	Tango::DevBoolean	memorizedFlipX;
/**
 *	Memorize/Define the flipY attribute at Init device<br>
 */
	Tango::DevBoolean	memorizedFlipY;
//@}

/**
 *    @name Device properties
 *    Device property member data.
 */
//@{
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *    @param cl    Class.
 *    @param s     Device Name
 */
    LimaDetector(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *    @param cl    Class.
 *    @param s     Device Name
 */
    LimaDetector(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *    @param cl    Class.
 *    @param s     Device name
 *    @param d    Device description.
 */
    LimaDetector(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one destructor is defined for this class */
//@{
/**
 * The object destructor.
 */    
    ~LimaDetector() {delete_device();};
/**
 *    will be called at device destruction or at init command.
 */
    void delete_device();
//@}

    
/**@name Miscellaneous methods */
//@{
/**
 *    Initialize the device
 */
    virtual void init_device();
/**
 *    Always executed method before execution command method.
 */
    virtual void always_executed_hook();

//@}

/**
 * @name LimaDetector methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
	virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for detectorDescription acquisition result.
 */
	virtual void read_detectorDescription(Tango::Attribute &attr);
/**
 *	Extract real attribute values for detectorType acquisition result.
 */
	virtual void read_detectorType(Tango::Attribute &attr);
/**
 *	Extract real attribute values for detectorModel acquisition result.
 */
	virtual void read_detectorModel(Tango::Attribute &attr);
/**
 *	Extract real attribute values for binnedWidthMax acquisition result.
 */
	virtual void read_binnedWidthMax(Tango::Attribute &attr);
/**
 *	Extract real attribute values for binnedHeightMax acquisition result.
 */
	virtual void read_binnedHeightMax(Tango::Attribute &attr);
/**
 *	Extract real attribute values for detectorPixelDepth acquisition result.
 */
	virtual void read_detectorPixelDepth(Tango::Attribute &attr);
/**
 *	Extract real attribute values for triggerMode acquisition result.
 */
	virtual void read_triggerMode(Tango::Attribute &attr);
/**
 *	Write triggerMode attribute values to hardware.
 */
	virtual void write_triggerMode(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for acquisitionMode acquisition result.
 */
	virtual void read_acquisitionMode(Tango::Attribute &attr);
/**
 *	Write acquisitionMode attribute values to hardware.
 */
	virtual void write_acquisitionMode(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for exposureTime acquisition result.
 */
	virtual void read_exposureTime(Tango::Attribute &attr);
/**
 *	Write exposureTime attribute values to hardware.
 */
	virtual void write_exposureTime(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for latencyTime acquisition result.
 */
	virtual void read_latencyTime(Tango::Attribute &attr);
/**
 *	Write latencyTime attribute values to hardware.
 */
	virtual void write_latencyTime(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for roiX acquisition result.
 */
	virtual void read_roiX(Tango::Attribute &attr);
/**
 *	Extract real attribute values for roiY acquisition result.
 */
	virtual void read_roiY(Tango::Attribute &attr);
/**
 *	Extract real attribute values for roiWidth acquisition result.
 */
	virtual void read_roiWidth(Tango::Attribute &attr);
/**
 *	Extract real attribute values for roiHeight acquisition result.
 */
	virtual void read_roiHeight(Tango::Attribute &attr);
/**
 *	Extract real attribute values for binningH acquisition result.
 */
	virtual void read_binningH(Tango::Attribute &attr);
/**
 *	Extract real attribute values for binningV acquisition result.
 */
	virtual void read_binningV(Tango::Attribute &attr);
/**
 *	Extract real attribute values for nbFrames acquisition result.
 */
	virtual void read_nbFrames(Tango::Attribute &attr);
/**
 *	Write nbFrames attribute values to hardware.
 */
	virtual void write_nbFrames(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for currentFrame acquisition result.
 */
	virtual void read_currentFrame(Tango::Attribute &attr);
/**
 *	Extract real attribute values for fileGeneration acquisition result.
 */
	virtual void read_fileGeneration(Tango::Attribute &attr);
/**
 *	Write fileGeneration attribute values to hardware.
 */
	virtual void write_fileGeneration(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for flipX acquisition result.
 */
	virtual void read_flipX(Tango::Attribute &attr);
/**
 *	Write flipX attribute values to hardware.
 */
	virtual void write_flipX(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for flipY acquisition result.
 */
	virtual void read_flipY(Tango::Attribute &attr);
/**
 *	Write flipY attribute values to hardware.
 */
	virtual void write_flipY(Tango::WAttribute &attr);
/**
 *	Read/Write allowed for detectorDescription attribute.
 */
	virtual bool is_detectorDescription_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for detectorType attribute.
 */
	virtual bool is_detectorType_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for detectorModel attribute.
 */
	virtual bool is_detectorModel_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for binnedWidthMax attribute.
 */
	virtual bool is_binnedWidthMax_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for binnedHeightMax attribute.
 */
	virtual bool is_binnedHeightMax_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for detectorPixelDepth attribute.
 */
	virtual bool is_detectorPixelDepth_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for triggerMode attribute.
 */
	virtual bool is_triggerMode_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for acquisitionMode attribute.
 */
	virtual bool is_acquisitionMode_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for exposureTime attribute.
 */
	virtual bool is_exposureTime_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for latencyTime attribute.
 */
	virtual bool is_latencyTime_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for roiX attribute.
 */
	virtual bool is_roiX_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for roiY attribute.
 */
	virtual bool is_roiY_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for roiWidth attribute.
 */
	virtual bool is_roiWidth_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for roiHeight attribute.
 */
	virtual bool is_roiHeight_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for binningH attribute.
 */
	virtual bool is_binningH_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for binningV attribute.
 */
	virtual bool is_binningV_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for nbFrames attribute.
 */
	virtual bool is_nbFrames_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for currentFrame attribute.
 */
	virtual bool is_currentFrame_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for fileGeneration attribute.
 */
	virtual bool is_fileGeneration_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for flipX attribute.
 */
	virtual bool is_flipX_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for flipY attribute.
 */
	virtual bool is_flipY_allowed(Tango::AttReqType type);
/**
 *	Execution allowed for Snap command.
 */
	virtual bool is_Snap_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Start command.
 */
	virtual bool is_Start_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Stop command.
 */
	virtual bool is_Stop_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetROI command.
 */
	virtual bool is_SetROI_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetBinning command.
 */
	virtual bool is_SetBinning_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ResetBinning command.
 */
	virtual bool is_ResetBinning_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ResetROI command.
 */
	virtual bool is_ResetROI_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetAttributeAvailableValues command.
 */
	virtual bool is_GetAttributeAvailableValues_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for OpenShutter command.
 */
	virtual bool is_OpenShutter_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for CloseShutter command.
 */
	virtual bool is_CloseShutter_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ResetFileIndex command.
 */
	virtual bool is_ResetFileIndex_allowed(const CORBA::Any &any);
/**
 * This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *	@return	State Code
 *	@exception DevFailed
 */
	virtual Tango::DevState	dev_state();
/**
 * Starts the acquisition of a number of frames equal to  'nbFrames' attribute value.
 *	@exception DevFailed
 */
	void	snap();
/**
 * Starts a "video/live" acquisition of an infinite number of frames.<br>
 *	In this mode, In this mode, the frame loss is permitted and not signaled as FAULT in the device state<br>
 *	It is not allowed to generate files in this mode.
 *	@exception DevFailed
 */
	void	start();
/**
 * Stop current acquisition/video.
 *	@exception DevFailed
 */
	void	stop();
/**
 * Define a Region of Interest . (OriginX, OriginY, Width, Height)<br>
 *	Roi and Binning are associated.
 *	@param	argin	[origin_x, origin_y, width, height]
 *	@exception DevFailed
 */
	void	set_roi(const Tango::DevVarULongArray *);
/**
 * Define a binning Horizontal (x) & Vertical (y) for the image. <br>
 *	@param	argin	
 *	@exception DevFailed
 */
	void	set_binning(const Tango::DevVarULongArray *);
/**
 * Use the binning Hrizontal=1 & Verical=1 of the detector according to current Roi.
 *	@exception DevFailed
 */
	void	reset_binning();
/**
 * Use the full frame of the detector according to current Binning.
 *	@exception DevFailed
 */
	void	reset_roi();
/**
 * Return a list of string containing all available values of a DevString attribute.
 *	@param	argin	Attribute name
 *	@return	List of strings containing the available values
 *	@exception DevFailed
 */
	Tango::DevVarStringArray	*get_attribute_available_values(Tango::DevString);
/**
 * Open the shutter in case of Shutter being in available and in Manual Mode
 *	@exception DevFailed
 */
	void	open_shutter();
/**
 * Close the shutter in case of Shutter being in available and in Manual Mode
 *	@exception DevFailed
 */
	void	close_shutter();
/**
 * Reset the file index
 *	@exception DevFailed
 */
	void	reset_file_index();

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

    //    Here is the end of the automatic code generation part
    //-------------------------------------------------------------    

	//method in charge of displaying image in the "image" dynamic attribute
    void    read_image_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);

    void    read_shutterMode_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);
    void    write_shutterMode_callback(yat4tango::DynamicAttributeWriteCallbackData& cbd);

    void    read_shutterOpenTime_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);
    void    write_shutterOpenTime_callback(yat4tango::DynamicAttributeWriteCallbackData& cbd);

    void    read_shutterCloseTime_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);
    void    write_shutterCloseTime_callback(yat4tango::DynamicAttributeWriteCallbackData& cbd);

    void    read_shutterState_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);

    void    read_exposureAccTime_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);
    void    write_exposureAccTime_callback(yat4tango::DynamicAttributeWriteCallbackData& cbd);
    
    void    read_currentAccFrame_callback(yat4tango::DynamicAttributeReadCallbackData& cbd);

    // return true if the device is correctly initialized in init_device
    bool    is_device_initialized(){return m_is_device_initialized;};

    /*******************************************************************
     * \class EventCallback
     * \brief Class that will receive the lima events
     *******************************************************************/
    /*class EventCallback : public lima::EventCallback
    {
	    DEB_CLASS_NAMESPC(DebModCamera, "EventCallback", "LimaDetector");

     public:
	    EventCallback();
	    virtual ~EventCallback();

     protected:
         virtual void processEvent(lima::Event *my_event);
    };*/

protected :    
    //    Add your own data members here
    //-----------------------------------------
    
    //Create Yat::task to manage device Start/Snap/Stop commands
    bool                create_acquisition_task(void);    
        
    //print parameters acquisition
    void                print_acq_conf();

    //get the last frame number acquired
    long long           get_last_image_counter(void);
    
    //state & status stuff
    bool                                m_is_device_initialized ;
    stringstream                        m_status_message;
    static int                          m_init_count;		//indicate when the construction of "generic" device is completed.

    //LIMA objects
    HwInterface*                        m_hw;				//object to the generic interface of camera's
    CtControl*                          m_ct;    			//object to Lima, the MAIN object
    CtSaving::Parameters                m_saving_par;		//struct holding parameters used when saving image in a file (NXS, EDF, ...)
    string                              m_trigger_mode; 	//trigger mode name 	(INTERNAL_SINGLE, EXTERNAL_SINGLE, EXTERNAL_MULTI, EXTERNAL_GATE, INTERNAL_MULTI, EXTERNAL_START_STOP, EXTERNAL_READOUT)
    string                              m_shutter_mode; 	//shutter mode name 	(MANUAL, AUTO_FRAME, AUTO_SEQUENCE)
    string                              m_acquisition_mode;	//aquisition mode name 	(SINGLE, ACCUMULATION) nota: imageType is forced to 32 bits in ACCUMULATION MODE

    //-Yat::task objects, manage device Start/Snap/Stop commands
    AcquisitionTask*                    m_acquisition_task;
    AcquisitionTask::AcqConfig          m_acq_conf;
    
    //- yat image Dynamic Attribute
    DynamicAttributeManager*            m_dam;

};

}    // namespace_ns

#endif    // _LimaDetector_H
