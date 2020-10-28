
#include "mender-dbus.h"

static gboolean
on_handle_get_jwt_token(MenderComMenderAuthentication1 *interface,
                        GDBusMethodInvocation *invocation, gpointer user_data) {

  gchar *response;
  response = g_strdup_printf("Hello JWT token");
  mender_com_mender_authentication1_complete_get_jwt_token(
      interface, invocation, response);
  g_free(response);

  return TRUE;
}

int main() {
  MenderComMenderAuthentication1 *interface;
  interface = mender_com_mender_authentication1_skeleton_new();

  g_signal_connect(interface, "handle-get-jwt-token",
                   G_CALLBACK(on_handle_get_jwt_token), NULL);

  // Need to init this connection somehow
  GDBusConnection *connection = NULL; // ???

  GError *error = NULL;
  if (!g_dbus_interface_skeleton_export(
          G_DBUS_INTERFACE_SKELETON(interface), connection,
          "/com/mender/AuthenticationManager1", &error)) {
    /* handle error */
  }

  while (1)
    ;
}
