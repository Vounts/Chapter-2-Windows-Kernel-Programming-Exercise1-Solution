
#include "Driver.h"
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
	UNREFERENCED_PARAMETER(pRegistryPath);
	KdPrint(("Successfully loaded the kmdf driver"));

	pDriverObject->DriverUnload = DriverUnloadRoutine;

	_OSVERSIONINFOW version;
	version.dwOSVersionInfoSize = sizeof(version);
	NTSTATUS status = RtlGetVersion(&version);
	if (!NT_SUCCESS(status))
	{
		KdPrint(("Failed to retrieve windows version!"));
		return STATUS_FWP_NULL_POINTER;
	}

	KdPrint(("Retrieving Version info... "));
	KdPrint(("Windows major: %d ", version.dwMajorVersion));
	KdPrint(("Windows minor: %d ", version.dwMinorVersion));
	KdPrint(("Windows build number: %d ", version.dwBuildNumber));

	return STATUS_SUCCESS;
}

void DriverUnloadRoutine(PDRIVER_OBJECT pDriverObject)
{
	UNREFERENCED_PARAMETER(pDriverObject);
	KdPrint(("Successfully Unloaded Driver"));
}

