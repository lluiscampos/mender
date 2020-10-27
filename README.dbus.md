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


### Code generation

Using gdbus-codegen. See Example section at https://developer.gnome.org/gio/stable/gdbus-codegen.html

See also https://www.freedesktop.org/software/gstreamer-sdk/data/docs/latest/gio/ch30s05.html

```
cd specs
make
```
