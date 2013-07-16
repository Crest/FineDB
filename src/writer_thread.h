#ifndef __WRITER_THREAD_H__
#define __WRITER_THREAD_H__

#include "ybin.h"

/**
 * typedef	writer_action_t
 *		Type of writer's action.
 * @const	WRITE_PUT	Add or update a key in database.
 * @const	WRITE_DEL	Remove a key from database.
 */
typedef enum writer_action_e {
	WRITE_PUT = 0,
	WRITE_DEL
} writer_action_t;

/**
 * @typedef	writer_msg_t
 *		Structure used to transfer data to the writer thread.
 * @field	type		Type of action (WRITE_PUT, WRITE_DEL).
 * @field	name		Key.
 * @field	data		Data.
 */
typedef struct writer_msg_s {
	writer_action_t type;
	ybin_t name;
	ybin_t data;
} writer_msg_t;

/**
 * @function	writer_loop
 *		Callback function executed by the writer thread.
 * @param	param	Pointer to the main FineDB structure.
 * @return	Always NULL.
 */
void *writer_loop(void *param);

#endif /* __WRITER_THREAD_H__ */
