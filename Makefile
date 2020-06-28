#############################################################################
# Makefile for building: mygame
# Generated by qmake (3.1) (Qt 5.10.0)
# Project:  mygame.pro
# Template: app
# Command: D:\Qtnew\5.10.0\mingw53_32\bin\qmake.exe -o Makefile mygame.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\Qtnew\5.10.0\mingw53_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\Qtnew\5.10.0\mingw53_32\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\Qtnew\5.10.0\mingw53_32\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: mygame.pro ../../Qtnew/5.10.0/mingw53_32/mkspecs/win32-g++/qmake.conf ../../Qtnew/5.10.0/mingw53_32/mkspecs/features/spec_pre.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/qdevice.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/device_config.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/common/g++-base.conf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/common/angle.conf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/common/windows-vulkan.conf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/common/sanitize.conf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/common/gcc-base.conf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/qconfig.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3drender.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axbase.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axserver.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_charts.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_charts_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_core.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_core_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_datavisualization.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_datavisualization_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_dbus.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_designer.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_edid_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gui.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_help.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_help_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_location.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_location_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_network.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_network_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_networkauth.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_networkauth_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_nfc.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_opengl.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_positioning.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qml.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quick.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_remoteobjects.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_repparser.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_repparser_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_script.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_script_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scxml.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sensors.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialport.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sql.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_svg.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_testlib.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_texttospeech.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_texttospeech_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_uitools.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_websockets.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_widgets.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_winextras.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xml.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qt_functions.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qt_config.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/win32-g++/qmake.conf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/exclusive_builds.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/toolchain.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/default_pre.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/win32/default_pre.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/resolve_config.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/exclusive_builds_post.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/default_post.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qml_debug.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/precompile_header.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/warn_on.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qt.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/resources.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/moc.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/win32/opengl.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/uic.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qmake_use.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/file_copies.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/win32/windows.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/testcase_targets.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/exceptions.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/yacc.prf \
		../../Qtnew/5.10.0/mingw53_32/mkspecs/features/lex.prf \
		mygame.pro \
		../../Qtnew/5.10.0/mingw53_32/lib/qtmaind.prl \
		../../Qtnew/5.10.0/mingw53_32/lib/Qt5Multimedia.prl \
		../../Qtnew/5.10.0/mingw53_32/lib/Qt5Widgets.prl \
		../../Qtnew/5.10.0/mingw53_32/lib/Qt5Gui.prl \
		../../Qtnew/5.10.0/mingw53_32/lib/Qt5Network.prl \
		../../Qtnew/5.10.0/mingw53_32/lib/Qt5Core.prl
	$(QMAKE) -o Makefile mygame.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/spec_pre.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/qdevice.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/device_config.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/common/g++-base.conf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/common/angle.conf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/common/windows-vulkan.conf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/common/sanitize.conf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/common/gcc-base.conf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/qconfig.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3drender.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axbase.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axserver.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_charts.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_charts_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_core.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_core_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_datavisualization.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_datavisualization_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_dbus.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_designer.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_edid_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gui.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_help.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_help_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_location.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_location_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_network.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_network_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_networkauth.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_networkauth_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_nfc.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_opengl.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_positioning.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qml.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quick.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_remoteobjects.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_remoteobjects_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_repparser.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_repparser_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_script.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_script_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scxml.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sensors.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialport.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sql.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_svg.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_testlib.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_texttospeech.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_texttospeech_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_uitools.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_websockets.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_widgets.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_winextras.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xml.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qt_functions.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qt_config.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/win32-g++/qmake.conf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/spec_post.prf:
.qmake.stash:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/exclusive_builds.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/toolchain.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/default_pre.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/win32/default_pre.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/resolve_config.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/exclusive_builds_post.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/default_post.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qml_debug.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/precompile_header.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/warn_on.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qt.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/resources.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/moc.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/win32/opengl.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/uic.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/qmake_use.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/file_copies.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/win32/windows.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/testcase_targets.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/exceptions.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/yacc.prf:
../../Qtnew/5.10.0/mingw53_32/mkspecs/features/lex.prf:
mygame.pro:
../../Qtnew/5.10.0/mingw53_32/lib/qtmaind.prl:
../../Qtnew/5.10.0/mingw53_32/lib/Qt5Multimedia.prl:
../../Qtnew/5.10.0/mingw53_32/lib/Qt5Widgets.prl:
../../Qtnew/5.10.0/mingw53_32/lib/Qt5Gui.prl:
../../Qtnew/5.10.0/mingw53_32/lib/Qt5Network.prl:
../../Qtnew/5.10.0/mingw53_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile mygame.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
