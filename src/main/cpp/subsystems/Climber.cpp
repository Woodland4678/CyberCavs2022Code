// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "subsystems/Climber.h"
#include <frc/smartdashboard/SmartDashboard.h>

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

Climber::Climber(){
    SetName("Climber");
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    SetSubsystem("Climber");

 AddChild("LevelLimit", &m_levelLimit);
 

 AddChild("LockLimit", &m_lockLimit);
 

 AddChild("ReadLimit2", &m_readLimit2);
 

 AddChild("ReachLimit1", &m_reachLimit1);
 

 AddChild("HeightSolenoid", &m_heightSolenoid);
 

 AddChild("LockSolenoid", &m_lockSolenoid);
 

 AddChild("ReachSolenoid", &m_reachSolenoid);
 
//rev::CANSparkMax m_followMotor{10, rev::CANSparkMax::MotorType::kBrushless};
 
 
//rev::CANSparkMax m_leaderMotor{9, rev::CANSparkMax::MotorType::kBrushless};
 
 

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    
    m_followMotor.Follow(m_leaderMotor);
    m_climberPidController.SetP(0.075);
    m_climberPidController.SetI(0);
    m_climberPidController.SetD(0);
    m_climberPidController.SetOutputRange(-0.50, 0.50);
}

void Climber::Periodic() {
    // Put code here to be run every loop
    frc::SmartDashboard::PutNumber("Climber Level", m_levelLimit.Get());
    frc::SmartDashboard::PutNumber("Climber Speed", m_climberEncoder.GetVelocity());
    frc::SmartDashboard::PutNumber("Climber Position", m_climberEncoder.GetPosition());

}

void Climber::SimulationPeriodic() {
    // This method will be called once per scheduler run when in simulation

}
void Climber::SetClimberPower(double pwr) {
    //m_climberPidController.SetReference(pwr, rev::ControlType::kVelocity);
    m_leaderMotor.Set(pwr);
}

bool isClicked = true;

bool Climber::CalibrateClimber(){
    if (!m_levelLimit.Get()&&isClicked){
        SetClimberPower(-0.3);
    }

    else if(m_levelLimit.Get()){
        SetClimberPower(0.3);
        isClicked=false;
    }else{
        m_climberEncoder.SetPosition(0);
        isClicked = true;
        m_leaderMotor.StopMotor();
        return true;
    }

    return false;
}


void Climber::SetClimberPosition(double position){
    m_climberPidController.SetReference(position, rev::ControlType::kPosition);
}


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.
