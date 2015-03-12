#include "WindowsFileDialog.h"
#include <sstream>
#include <locale>
#include <codecvt>

WindowsFileDialog::WindowsFileDialog()
{
	_success = false;
}

WindowsFileDialog::WindowsFileDialog(std::vector<COMDLG_FILTERSPEC> filterSpec)
	: _filterSpecifications(filterSpec)
{
	_success = false;
}

void WindowsFileDialog::openDialog()
{
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	//Create an instance of the file open dialog
	IFileOpenDialog* dialog;
	CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, (void**)&dialog);

	//If any filters have been assigned then use them
	if(_filterSpecifications.size() > 0)
		dialog->SetFileTypes(_filterSpecifications.size(), &_filterSpecifications[0]);

	//Show the dialog
	HRESULT result = dialog->Show(NULL);
	_success = SUCCEEDED(result);
	
	//If the user clicked ok then save the file's path
	if(_success)
	{
		IShellItem* item;
		dialog->GetResult(&item);

		PWSTR filePath;
		item->GetDisplayName(SIGDN_FILESYSPATH, &filePath);

		//Convert the file's path from a wstring to a string
		std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> wsc;
		_filePath = wsc.to_bytes(filePath);

		//Cleanup
		CoTaskMemFree(filePath);
		item->Release();
		dialog->Release();
	}

	CoUninitialize();
}

std::string WindowsFileDialog::getFilePath()
{
	return _filePath;
}

bool WindowsFileDialog::isFileChosen()
{
	return _success;
}