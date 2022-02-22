// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Command.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

#include "commands/IntakeRetract.h"

IntakeRetract::IntakeRetract(Intake* m_intake)
:m_intake(m_intake){

    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("IntakeRetract");
    AddRequirements({m_intake});

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

}

// Called just before this Command runs the first time
void IntakeRetract::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeRetract::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeRetract::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void IntakeRetract::End(bool interrupted) {

}

bool IntakeRetract::RunsWhenDisabled() const {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DISABLED
    return false;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DISABLED
}
