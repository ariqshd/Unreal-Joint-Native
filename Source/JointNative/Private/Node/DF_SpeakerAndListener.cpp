//Copyright 2022~2024 DevGrain. All Rights Reserved.

#include "Node/DF_SpeakerAndListener.h"

#include "Node/DF_Participant.h"

#include "JointVersionComparison.h"

UDF_SpeakerAndListener::UDF_SpeakerAndListener()
{
	
#if WITH_EDITORONLY_DATA

#if JOINT_VERSION_OLDER_THAN(2, 9, 0)
	
	bUseSpecifiedGraphNodeBodyColor = true;
	NodeBodyColor = FLinearColor(0.05f, 0.15f, 0.2f, 0.4);
	DefaultEdSlateDetailLevel = EJointEdSlateDetailLevel::SlateDetailLevel_Minimal_Content;

#else

	EdNodeSetting.bUseSpecifiedGraphNodeBodyColor = true;
	EdNodeSetting.NodeBodyColor = FLinearColor(0.05f, 0.15f, 0.2f, 0.4);
	EdNodeSetting.DefaultEdSlateDetailLevel = EJointEdSlateDetailLevel::SlateDetailLevel_Minimal_Content;

#endif
	
#endif
	
}

TArray<UDF_Participant*> UDF_SpeakerAndListener::GetSpeakerParticipants() const
{
	TArray<UDF_Participant*> OutArray;
	
	for (FJointNodePointer Speaker : Speakers)
	{
		if(Speaker.Node == nullptr)continue;
		
		if(UDF_Participant* Participant = Cast<UDF_Participant>(Speaker.Node.Get()))
		{
			OutArray.Add(Participant);
		}
	}

	return OutArray;
}

TArray<UDF_Participant*> UDF_SpeakerAndListener::GetListenerParticipants() const
{
	TArray<UDF_Participant*> OutArray;
	
	for (FJointNodePointer Listener : Listeners)
	{
		if(Listener.Node == nullptr)continue;
		
		if(UDF_Participant* Participant = Cast<UDF_Participant>(Listener.Node.Get()))
		{
			OutArray.Add(Participant);
		}
	}

	return OutArray;

}

TArray<FJointNodePointer> UDF_SpeakerAndListener::GetSpeakers()
{
	return Speakers;
}

TArray<FJointNodePointer> UDF_SpeakerAndListener::GetListeners()
{
	return Listeners;
}


void UDF_SpeakerAndListener::SetSpeakers(TArray<FJointNodePointer> InSpeakers)
{
	Speakers = InSpeakers;
}

void UDF_SpeakerAndListener::SetListeners(TArray<FJointNodePointer> InListeners)
{
	Listeners = InListeners;
}

TArray<UDF_Participant*> UDF_SpeakerAndListener::GetSpeakerParticipantList_Implementation()
{
	return GetSpeakerParticipants();
}

TArray<UDF_Participant*> UDF_SpeakerAndListener::GetListenerParticipantList_Implementation()
{
	return GetListenerParticipants();
}
