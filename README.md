# snapcraft-preload-glib-test
test of snapcraft preload with glib/gio

The error only occurs on the second invocation and subsequent tries. This is because the file being replaced does not exist on the first try, and thus does not need the metadata copied. The second and further attempts all fail because GLib is writing the content into a new file, copying the metadata such as owner and mode, and then renaming over the original file atomically. The copying of metadata is the problem here, because it does an fchown call using the original file's ownership as the arguments.
