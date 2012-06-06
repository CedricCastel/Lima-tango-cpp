static const char *RcsId = "$Id $";
//+=============================================================================
//
// file :        main.cpp
//
// description : C++ source for a TANGO device server main.
//               The main rule is to initialise (and create) the Tango
//               system and to create the DServerClass singleton.
//               The main should be the same for every Tango device server.
//
// project :     TANGO Device Server
//
// $Author:  $
//
// $Revision:  $ $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//-=============================================================================
//
//          This file is generated by POGO
//    (Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#include <tango.h>


#if defined(ENABLE_CRASH_REPORT)
# include <crashreporting/crash_report.h>
#else
# define DECLARE_CRASH_HANDLER
# define INSTALL_CRASH_HANDLER
#endif

DECLARE_CRASH_HANDLER;

int main(int argc,char *argv[])
{
	INSTALL_CRASH_HANDLER;
    
    Tango::Util *tg;

    try
    {
        // Initialise the device server
        //----------------------------------------
        tg = Tango::Util::init(argc,argv);

        // Create the device server singleton 
        //    which will create everything
        //----------------------------------------
        tg->server_init(false);

        // Run the endless loop
        //----------------------------------------
        cout << "Ready to accept request" << endl;
        tg->server_run();
    }
    catch (bad_alloc)
    {
        cout << "Can't allocate memory to store device object !!!" << endl;
        cout << "Exiting" << endl;
    }
    catch (CORBA::Exception &e)
    {
        Tango::Except::print_exception(e);
        
        cout << "Received a CORBA_Exception" << endl;
        cout << "Exiting" << endl;
    }
    tg->server_cleanup();

    return(0);
}
