#include "context.h"

const struct context default_context = {
  .running = false,
  .window = NULL,
  .renderer = NULL,
  .texture = NULL
};