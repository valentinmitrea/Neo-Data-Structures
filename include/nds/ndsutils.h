/**
 * NDS - Neo Data Structures
 * Copyright (C) 2017-2018 MiVal Software
 *
 * This file is part of Neo Data Structures.
 *
 * Neo Data Structures is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Neo Data Structures is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Neo Data Structures. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * This file contains various utilities needed by the NDS library.
 *
 * @author      Valentin Gabriel Mitrea <mitrea.valentin@gmail.com>
 * @created     23 February 2018
 * @modified    23 February 2018
 */

#ifndef __NDS_UTILS_H__
#define __NDS_UTILS_H__


enum NdsStatus
{
	NDS_OK                  = 0,
	NDS_ERROR               = 1,
	NDS_INVALID_PARAM_ERROR = 2,
	NDS_MEM_ALLOC_ERROR     = 3
};

typedef enum NdsStatus NdsStatus;


#endif /* __NDS_UTILS_H__ */
