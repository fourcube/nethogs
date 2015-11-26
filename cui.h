/* NetHogs console UI */

void do_refresh ();
void init_ui ();
void exit_ui ();

/* periodically gives some CPU-time to the UI */
void ui_tick ();


// viewMode: kb/s or total
int VIEWMODE_KBPS = 0;
int VIEWMODE_TOTAL_KB = 1;
int VIEWMODE_TOTAL_B = 2;
int VIEWMODE_TOTAL_MB = 3;
int viewMode = VIEWMODE_KBPS;
int nViewModes = 4;