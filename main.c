#include <glib.h>
#include <gio/gio.h>

static GFile *get_file(const gchar *parent, const gchar *filepath) {
    GFile   *file  = g_file_new_for_path(parent);
    GFile   *child = g_file_get_child(file, filepath);

    g_object_unref (file);
    file = child;

    return file;
}

void main(void) {
    GError *error = NULL;
    GFile  *file  = get_file(g_getenv("SNAP_USER_DATA"), "test-glib-file");
    gchar  *name  = g_file_get_parse_name(file);

    g_print ("Writing '%s'\n", name);

    GOutputStream *output = G_OUTPUT_STREAM(g_file_replace(file,
                                            NULL, FALSE, G_FILE_CREATE_NONE,
                                            NULL, &error));
    if (output) {
        g_print("successfully opened '%s'\n", name);
    } else {
        g_print("failed to open '%s'\n", name);
    }
}