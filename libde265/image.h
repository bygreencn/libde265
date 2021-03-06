/*
 * H.265 video codec.
 * Copyright (c) 2013 StrukturAG, Dirk Farin, <farin@struktur.de>
 *
 * This file is part of libde265.
 *
 * libde265 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * libde265 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libde265.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DE265_IMAGE_H
#define DE265_IMAGE_H

#include <stdint.h>
#include "libde265/de265.h"


typedef struct de265_image {
  uint8_t* y;   // pointer to pixel at (0,0), which is inside the optional image borders
  uint8_t* cb;
  uint8_t* cr;

  uint8_t* y_mem;  // usually, you don't use these, but the pointers above
  uint8_t* cb_mem;
  uint8_t* cr_mem;

  enum de265_chroma chroma_format;

  int width, height;  // size in luma pixels
  int chroma_width, chroma_height;
  int stride, chroma_stride;

  int border;
} de265_image;

void de265_init_image (de265_image* img); // (optional) init variables, do not alloc image
void de265_alloc_image(de265_image* img, int w,int h, enum de265_chroma c, int border);
void de265_free_image (de265_image* img);

void de265_fill_image(de265_image* img, int y,int u,int v);
void de265_copy_image(de265_image* dest, const de265_image* src);

#endif
