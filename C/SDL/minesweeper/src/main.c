#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.h"
#include "context.h"

int main()
{
	struct context context = default_context;

	return execute(&context);
}
