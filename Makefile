#
# OMNeT++/OMNEST Makefile for UAVSim
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -KINET_PROJ=../inet -I. -I$$\(INET_PROJ\)/src -L$$\(INET_PROJ\)/out/$$\(CONFIGNAME\)/src -lINET
#

# Name of target to be created (-o option)
TARGET = UAVSim$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = -I. -I$(INET_PROJ)/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(INET_PROJ)/out/$(CONFIGNAME)/src  -lINET

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/uavnet/applications/pingapp/PingTestApp.o \
    $O/uavnet/common/GlobalWirelessLinkInspector.o \
    $O/uavnet/linklayer/xmac/AnyMacXmacLayer.o \
    $O/uavnet/routing/manet/base/ManetAddress.o \
    $O/uavnet/routing/manet/base/ManetNetfilterHook.o \
    $O/uavnet/routing/manet/base/ManetRoutingBase.o \
    $O/uavnet/routing/manet/dsr/dsr-pkt_omnet.o \
    $O/uavnet/routing/manet/dsr/dsr-uu-omnetpp.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-ack.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-io.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-opt.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-pkt.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-rerr.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-rrep.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-rreq.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr-srt.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/dsr_access_database.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/DsrDataBase.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/maint-buf.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/neigh.o \
    $O/uavnet/routing/manet/dsr/dsr-uu/send-buf.o \
    $O/uavnet/routing/manet/olsr/OLSR.o \
    $O/uavnet/routing/manet/olsr/OLSR_ETX.o \
    $O/uavnet/routing/manet/olsr/OLSR_ETX_dijkstra.o \
    $O/uavnet/routing/manet/olsr/OLSR_ETX_state.o \
    $O/uavnet/routing/manet/olsr/OLSR_rtable.o \
    $O/uavnet/routing/manet/olsr/OLSR_state.o \
    $O/uavnet/routing/manet/olsr/OLSROPT.o \
    $O/uavnet/linklayer/xmac/XMacPkt_m.o \
    $O/uavnet/routing/manet/base/ControlInfoBreakLink_m.o \
    $O/uavnet/routing/manet/base/ControlManetRouting_m.o \
    $O/uavnet/routing/manet/base/LocatorNotificationInfo_m.o \
    $O/uavnet/routing/manet/base/MeshControlInfo_m.o \
    $O/uavnet/routing/manet/olsr/OLSRpkt_m.o

# Message files
MSGFILES = \
    uavnet/linklayer/xmac/XMacPkt.msg \
    uavnet/routing/manet/base/ControlInfoBreakLink.msg \
    uavnet/routing/manet/base/ControlManetRouting.msg \
    uavnet/routing/manet/base/LocatorNotificationInfo.msg \
    uavnet/routing/manet/base/MeshControlInfo.msg \
    uavnet/routing/manet/olsr/OLSRpkt.msg

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = $(OPPMAIN_LIB) $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)
ifneq ($(TOOLCHAIN_NAME),clangc2)
LIBS += -Wl,-rpath,$(abspath $(INET_PROJ)/out/$(CONFIGNAME)/src)
endif

COPTS = $(CFLAGS) $(IMPORT_DEFINES)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

# include all dependencies
-include $(OBJS:%.o=%.d)
