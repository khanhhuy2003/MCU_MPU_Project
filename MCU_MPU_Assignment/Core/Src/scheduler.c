/*
 * scheduler.c
 *
 *  Created on: Dec 7, 2023
 *      Author: ASUS
 */

#include "main.h"
#include "scheduler.h"

typedef struct {
	void (*pTask) (void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

static sTask SCH_tasks_G[SCH_MAX_TASKS];
static uint32_t newTaskID = 0;
static uint32_t count_SCH_Update = 0;

void SCH_Init(void){

}

void SCH_Update(void) {

}

uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD){

}

uint8_t SCH_Delete_Task(uint32_t taskID){

}

void SCH_Dispatch_Tasks(void){

}

static uint32_t Get_New_Task_ID(void){

}
