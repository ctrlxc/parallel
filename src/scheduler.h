/*
  +----------------------------------------------------------------------+
  | parallel                                                              |
  +----------------------------------------------------------------------+
  | Copyright (c) Joe Watkins 2019                                       |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
 */
#ifndef HAVE_PARALLEL_SCHEDULER_H
#define HAVE_PARALLEL_SCHEDULER_H

void php_parallel_scheduler_init(zend_llist *schedule);

void php_parallel_scheduler_push(
        zend_llist *schedule, 
        php_parallel_monitor_t *monitor, 
        zend_function *function, 
        zval *argv, 
        zval *future);
        
zend_bool php_parallel_scheduler_pop(php_parallel_schedule_el_t *el);

zend_bool php_parallel_scheduler_executing();

zend_bool php_parallel_scheduler_may_yield(zend_execute_data *current, zend_execute_data *frame);

void php_parallel_scheduler_yield(zend_execute_data *frame);

void php_parallel_scheduler_run(php_parallel_monitor_t *monitor, zend_execute_data *frame);
php_parallel_t* php_parallel_scheduler_setup(php_parallel_t *parallel);

void php_parallel_scheduler_kill();
zend_bool php_parallel_scheduler_killed();
void php_parallel_scheduler_destroy(zend_llist *schedule);
#endif
