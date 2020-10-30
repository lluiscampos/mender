# DBus notes

### Versioning

See https://dbus.freedesktop.org/doc/dbus-api-design.html#api-versioning

So, object `/com/mender/AuthenticationManager1` instead of `/com/mender/AuthenticationManager`.

And interface `com.mender.Authentication1` instead of `com.mender.Authentication`.


### mender.io -> /io/mender/...?

"For example, version 2 of an address book application called ContactDex provided by a software vendor whose website is chocolateteapot.com would use service name com.chocolateteapot.ContactDex2."

Therefore, shouldn't we use io.mender... ?


### Documentation

We need to document the APIs in xml. See `spec/`

A good documented API: Telephathy. See https://telepathy.freedesktop.org/spec/

We can aim for something like Ubuntu location https://core.docs.ubuntu.com/en/stacks/location/location-service/docs/reference/dbus-api

#### Notes on code generation

The produced markdown is somewhat incomplete:

* XML: refsynopsisdiv -> refsect1
* XML: remove refmeta (leading com.mender.Authentication1)
* MD:  Add H1 marker to Authentication API v1
* XML? Header methods/signals to shell like (same as below)
* ???  Remove or fix anchors


#### Tutorial

Python tutorial based on pydbus https://github.com/LEW21/pydbus

Or https://dbus.freedesktop.org/doc/dbus-python/dbus.html ??


### Code generation

Using gdbus-codegen. See Example section at https://developer.gnome.org/gio/stable/gdbus-codegen.html

See also https://www.freedesktop.org/software/gstreamer-sdk/data/docs/latest/gio/ch30s05.html

```
cd specs
make
```

I tried also:

* https://github.com/stratis-storage/dbus-client-gen
* https://github.com/stratis-storage/dbus-python-client-gen
* https://github.com/amenzhinsky/dbus-codegen-go

### Distribution of spec files

On Debian, they are installed at /usr/share/dbus-1/interfaces/

See for example https://packages.debian.org/buster/amd64/dolphin-dev/filelist

To find packages that provide D-Bus API spec files:

```
apt-get install apt-file
apt-file update
apt-file find /usr/share/dbus-1/interfaces
```
