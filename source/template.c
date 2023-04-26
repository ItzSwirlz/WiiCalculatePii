#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <limits.h>
static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	// Initialise the video system
	VIDEO_Init();

	// This function initialises the attached controllers
	WPAD_Init();

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the console, required for printf
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();


	// The console understands VT terminal escape codes
	// This positions the cursor on row 2, column 0
	// we can use variables for this with format codes too
	// e.g. printf ("\x1b[%d;%dH", row, column );
	printf("\x1b[2;0H");

	printf("WARNING: The screen will flash to show the convergence of Pi as it happens. Press A to continue.\n");

	while(1) {

		// Call WPAD_ScanPads each loop, this reads the latest controller states
		WPAD_ScanPads();

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		u32 pressed = WPAD_ButtonsDown(0);

		if(pressed & WPAD_BUTTON_A) {
			// Gregory-Leibniz series
			// (4/1) - (4/3) + (4/5) - (4/7) + (4/9)...
			// Doesn't converge to Pi as quickly as other methods.
			double ret = 4.0;
			bool negative = true;
			for(float i = 3.0; i <= INT_MAX; i += 2.0) {
				if(negative) {
					ret -= (4.0/i);
					negative = false;
				} else {
					ret += (4.0/i);
					negative = true;
				}

				// see the converging
				// 78 decimals is the most an HDTV should be able to handle (or at least on dolphin for me)
				printf("%.78lf\n", ret);
			}

			printf("\n");
		}

		// We return to the launcher application via exit
		if ( pressed & WPAD_BUTTON_HOME ) exit(0);

		// Wait for the next frame
		VIDEO_WaitVSync();
	}

	return 0;
}
