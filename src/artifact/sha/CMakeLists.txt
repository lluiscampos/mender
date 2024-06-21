add_library(sha STATIC)

if(${MENDER_SHA_OPENSSL})
  find_package(OpenSSL REQUIRED)
  if(NOT ${OpenSSL_Found})
    message(FATAL_ERROR "OpenSSL not found during build")
  endif()

  target_sources(sha PRIVATE sha.cpp platform/openssl/sha.cpp)
  target_link_libraries(sha PUBLIC OpenSSL::SSL OpenSSL::Crypto)
  target_link_libraries(sha PUBLIC common_log common_error common_io)
  target_compile_options(sha PRIVATE ${PLATFORM_SPECIFIC_COMPILE_OPTIONS})
  target_include_directories(sha PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

elseif(MENDER_SHA_STUB)
  target_sources(sha PRIVATE sha.cpp platform/stub/sha.cpp)
  target_link_libraries(sha PUBLIC common_log common_error common_io)
#  target_compile_options(sha PRIVATE ${PLATFORM_SPECIFIC_COMPILE_OPTIONS})
  target_include_directories(sha PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

else()
  message(FATAL_ERROR "Either MENDER_SHA_OPENSSL or MENDER_SHA_STUB needs to be enabled")
endif()
