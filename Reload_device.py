def my_reload_device(testbed, device):
    '''This function reloads the device
       call: my_reload_device(testbed, device)
    '''
    password = testbed.servers.tftp.password
    uut_username = testbed.tacacs['username']
    uut_password = testbed.passwords['tacacs']
    
    response = Dialog([
        [r'.*Warning: There is already a file existing with this name. Do you want to overwrite \(y/n\)\?\[n\] '
         , lambda spawn: spawn.sendline('y'), None, True, False],
        [r'.Warning: There is already a file existing with this name. Do you want to.'
         , lambda spawn: spawn.sendline('y'), None, True, False],
        [r'.*login\:', lambda spawn: spawn.sendline(uut_username), None,
         True, False],
        [r'Password\:', lambda spawn: spawn.sendline(uut_password),
         None, True, False],
        [r'.*\s+\(y/n\)\?\s+\[n\]', lambda spawn: spawn.sendline('y'),
         None, True, False],
        [r'Do you wish to proceed anyway\?\s+\(y/n\)\s+\[n\]',
         lambda spawn: spawn.sendline('y'), None, True, False],
        ])
    try:
        device.execute("reload", reply = response, timeout = 1200)
    except Exception:
        log.error(traceback.format_exc())
        self.errored('error executing command reload')    
    time.sleep(360)
    disconnect_connect_device(device)
    return 1
