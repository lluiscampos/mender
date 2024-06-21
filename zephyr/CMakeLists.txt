if(CONFIG_MENDER_OTA)
  # Configure the build, like for example removing tests, or opting out of features
  set(BUILD_TESTS "off")

  set(MENDER_USE_DBUS "off")
  set(MENDER_EMBED_MENDER_AUTH "on")

  set(MENDER_USE_ASIO_LIBDBUS "off")

  set(MENDER_USE_BOOST_ASIO "off")
  set(MENDER_EVENTS_STUB "on")

  set(MENDER_USE_BOOST_BEAST "off")
  set(MENDER_HTTP_STUB "on")

  set(MENDER_USE_LMDB "off")
  set(MENDER_DB_STUB "on")

  set(MENDER_USE_NLOHMANN_JSON "on")

  set(MENDER_USE_TINY_PROC_LIB "off")
  set(MENDER_PROC_STUB "on")

  set(MENDER_SHA_OPENSSL "off")
  set(MENDER_SHA_STUB "on")

  set(MENDER_TAR_LIBARCHIVE "off")
  set(MENDER_TAR_STUB "on")

  set(MENDER_LOG_BOOST "off")
  set(MENDER_LOG_STUB "on")

  set(MENDER_CRYPTO_OPENSSL "off")
  set(MENDER_CRYPTO_STUB "on")

  set(MENDER_USE_SYSTEMD "off")

  set(MENDER_USE_POSIX "off")
  set(MENDER_POSIX_STUB "on")

  # Include the main project
  add_subdirectory(.. build)

  # Link our base INTERFACE library to zephyr_interface.
  # Every other library links with this one so the properties get propagated.
  zephyr_append_cmake_library(common_cpp)
  zephyr_link_interface(common_cpp)
  # Alternatively, we can collect all our libraries in a variable and do here for each:
  #   target_link_libraries(<library> PUBLIC zephyr_interface)
  #   set_property(GLOBAL APPEND PROPERTY ZEPHYR_LIBS <library>)
endif()
