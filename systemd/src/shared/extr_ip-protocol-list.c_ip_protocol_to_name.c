#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 size_t ELEMENTSOF (char const**) ; 
 char const** ip_protocol_names ; 

const char *ip_protocol_to_name(int id) {

        if (id < 0)
                return NULL;

        if ((size_t) id >= ELEMENTSOF(ip_protocol_names))
                return NULL;

        return ip_protocol_names[id];
}