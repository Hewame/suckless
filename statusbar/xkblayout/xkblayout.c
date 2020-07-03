#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/XKBlib.h>
#include <X11/extensions/XKBrules.h>

#ifdef DEBUG
#define DPRINTF_U(t) printf(#t"=%u\n", t)
#define DPRINTF_S(t) printf(#t"=%s\n", t)
#else
#define DPRINTF_U(t)
#define DPRINTF_S(t)
#endif

int
main(void)
{
	Display *dpy;
	XkbDescPtr desc;
	XkbStateRec state;
	XkbRF_VarDefsRec vd;
	char *group, *symbols;
	char *tmp, *str, *tok;
	unsigned int i;

	dpy = XOpenDisplay(NULL);
	if (dpy == NULL) {
		fprintf(stderr, "Cannot open display\n");
		exit(1);
	}

	/* Get layout group index in [0..3] */
	XkbGetState(dpy, XkbUseCoreKbd, &state);
	DPRINTF_U(state.group);

	/* Get layout names */
	desc = XkbGetKeyboard(dpy, XkbAllComponentsMask, XkbUseCoreKbd);
	group = XGetAtomName(dpy, desc->names->groups[state.group]);
	DPRINTF_S(group);
	symbols = XGetAtomName(dpy, desc->names->symbols);
	DPRINTF_S(symbols);

	/* Get clean layouts string */
	XkbRF_GetNamesProp(dpy, &tmp, &vd);
	DPRINTF_S(tmp);
	DPRINTF_S(vd.layout);

	str = strdup(vd.layout);

	/* Tokenize until we reach the current layout */
	tok = strtok(str, ",");
	for (i = 0; i < state.group; i++) {
		tok = strtok(NULL, ",");
		if (tok == NULL)
			return 1;
		DPRINTF_S(tok);
	}

	/* Print layout name */
	printf("%s\n", tok);

	free(str);

	return 0;
}
