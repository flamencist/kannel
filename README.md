# kannel
конфигурационные файлы и мануал по установке из исходников

1. скачиваем ubuntu 14.04 - http://releases.ubuntu.com/14.04/

2. скачиваем http://www.kannel.org/download/1.5.0/gateway-1.5.0.tar.gz<br\>
 `wget http://www.kannel.org/download/1.5.0/gateway-1.5.0.tar.gz`<br\>
 распаковывем архив<br\>
 `tar -xzf gateway-1.5.0.tar.gz`

3. устанавливаем библиотеки для компиляции и сборки<br\>
`sudo apt-get install build-essential`<br\>
`sudo apt-get install libxml2 libxml2-dev`

4. конфигурируем сборку <br\>
`sudo mkdir /usr/local/kannel`<br\>
`sudo ./configure --prefix=/usr/local/kannel  --–enable-start-stop-daemon`

5. компилим и собираем<br\>
`sudo make`<br\>
`sudo make install`

6. создаем файл для запуска\остановки kannel (используется файл kannel)<br\>
`sudo vi /etc/init.d/kannel`<br\>
`sudo chmod +x /etc/init.d/kannel`<br\>
`sudo update-rc.d kannel defaults`<br\>
`sudo mkdir /var/lock/subsys`<br\>
`sudo mkdir /var/log/kannel`

7. создаем конфигурационный файл /etc/kannel/kannel.conf<br\>
`sudo mkdir /etc/kannel`<br\>
`sudo vi /etc/kannel/kannel.conf`

8. правим метод `convert_addr_from_pdu` в  файле `/gw/smsc/smsc_smpp.c` на строке  347<br\>
компилируем и билдим<br\>
`sudo make`<br\>
`sudo make install`

9. запускаем kannel <br\>
`sudo service kannel start`

10. проверяем http://yourip:13003/cgi-bin/sendsms?user=username&pass=pa$$w0rd&charset=UTF-8&coding=2&to=yourphone65789031&text=text

