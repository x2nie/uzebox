/*
 *  Uzebox video mode 42 simple demo
 *  Copyright (C) 2018 Sandor Zsuga (Jubatian)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdbool.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <uzebox.h>



int main(){

	unsigned int i;
	unsigned int j;

	ClearVram();
	SetBorderColor(0xBFU);

	/* Fill VRAM */

	for (i = 0U; i < VRAM_SIZE; i++){
		aram[i] = (i     ) & 0xFFU;
	}

	for (i = 0U; i < VRAM_SIZE; i++){
		vram[i] = (i * 3U) & 0xFFU;
	}

	/* Bitmap modes */

	SetTileTableRow(M42_TILEROW_2BPP, 8U);
	SetTileTableRow(M42_TILEROW_2BPP, 9U);
	SetTileTableRow(M42_TILEROW_2BPP, 10U);
	SetTileTableRow(M42_TILEROW_2BPP, 11U);

	SetTileTableRow(M42_TILEROW_1BPP, 12U);
	SetTileTableRow(M42_TILEROW_1BPP, 13U);
	SetTileTableRow(M42_TILEROW_1BPP, 14U);
	SetTileTableRow(M42_TILEROW_1BPP, 15U);

	for (j = 0U; j < 16U; j ++){
		for (i = 0U; i < 32U; i ++){
			PutPixel(i + (j << 1) + 0U, i + 32U, j);
			PutPixel(i + (j << 1) + 1U, i + 32U, j);
		}
	}

	while(1);

}
