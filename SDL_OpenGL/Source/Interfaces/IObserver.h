#pragma once

#include "stdafx.h"

#include <vector>
#include <functional>

//typedef void(*Delegate)(); // Function delegate.
typedef std::function<void()> Delegate;

class IObserver
{
friend class ISubject;

public:
	IObserver() {}
	virtual ~IObserver();

	inline void SetOwningSubject(ISubject* InOwningSubject) { OwningSubject = InOwningSubject; }
	//inline void SetEventDelegate(Delegate InDelegateFunc) { OnEventDelegate = InDelegateFunc; }

	Delegate	OnEventDelegate;
protected:

	ISubject*	OwningSubject;

};

class ISubject 
{
public:

	/**
	*   @brief The only way of binding and unbinding observers is these two functions.
	*/
	void Bind(IObserver* InInterestedObserver);
	void Unbind(IObserver* InInterestedObserver);

protected:

	void Broadcast();
	std::string Name;

private:
	
	std::vector<IObserver*> ObserversList;

	std::vector<IObserver*>::iterator FindObserver(IObserver* InInterestedObserver);
	bool IsBound(IObserver* InInterestedObserver);

};