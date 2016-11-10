#include "IObserver.h"

IObserver::~IObserver()
{
	if (OwningSubject != nullptr)
	{
		OwningSubject->Unbind(this);
	}
}

void ISubject::Bind(IObserver* InInterestedObserver)
{
	if (IsBound(InInterestedObserver) == false)
	{
		InInterestedObserver->OwningSubject = this;
		ObserversList.push_back(InInterestedObserver);
	}
	else
	{
		Log(DebugType::EDT_Notice, "Cannot bind an observer. Already bound or delegate is null.");
	}
}

void ISubject::Unbind(IObserver* InInterestedObserver)
{
	std::vector<IObserver*>::iterator WantedObserver = FindObserver(InInterestedObserver);

	if (WantedObserver != ObserversList.end())
	{
		(*WantedObserver)->OwningSubject = nullptr;
		(*WantedObserver)->OnEventDelegate = nullptr;
		ObserversList.erase(WantedObserver);
	}

}

std::vector<IObserver*>::iterator ISubject::FindObserver(IObserver* InInterestedObserver)
{
	std::vector<IObserver*>::iterator FoundElement = std::find(ObserversList.begin(), ObserversList.end(), InInterestedObserver);

	return FoundElement;
}

bool ISubject::IsBound(IObserver* InInterestedObserver)
{
	if (FindObserver(InInterestedObserver) != ObserversList.end())
	{
		return true;
	}

	return false;
}

void ISubject::Broadcast()
{
	for (auto& iter = ObserversList.begin(); iter != ObserversList.end(); ++iter)
	{
		(*iter)->OnEventDelegate();
	}
}