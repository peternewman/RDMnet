# On Unix-like platforms, use Avahi.
# Use Avahi's compat layer for now...

set(RDMNET_DISC_PLATFORM_SOURCES
  ${RDMNET_SRC}/rdmnet/discovery/bonjour/disc_platform_defs.h
  ${RDMNET_SRC}/rdmnet/discovery/bonjour/rdmnet_disc_bonjour.c
)
add_library(RDMnetDiscoveryPlatform INTERFACE)
target_sources(RDMnetDiscoveryPlatform INTERFACE ${RDMNET_DISC_PLATFORM_SOURCES})
target_include_directories(RDMnetDiscoveryPlatform INTERFACE
  ${RDMNET_SRC}/rdmnet/discovery/bonjour
)
target_link_libraries(dnssd INTERFACE dns_sd)

#set(RDMNET_DISC_PLATFORM_SOURCES
#  ${RDMNET_SRC}/rdmnet/discovery/avahi/disc_platform_defs.h
#  ${RDMNET_SRC}/rdmnet/discovery/avahi/rdmnet_disc_avahi.c
#)
#add_library(RDMnetDiscoveryPlatform INTERFACE)
#target_sources(RDMnetDiscoveryPlatform INTERFACE ${RDMNET_DISC_PLATFORM_SOURCES})
#target_include_directories(RDMnetDiscoveryPlatform INTERFACE
#  ${RDMNET_SRC}/rdmnet/discovery/avahi
#)
#target_link_libraries(dnssd INTERFACE avahi-client avahi-common)
