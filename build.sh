#!/bin/bash


#################################################################
# Define functions necessary for building Obsidian              #
#################################################################

cleandeps(){
	rm -rf LATEST.tar.gz
	rm -rf libsodium*
}

build(){
	cd src
	sudo chmod +x buildquick.sh
	sudo ./buildquick.sh
}
init(){
        mkdir -p ~/.obsidian && touch $_/obsidian.conf
        config=~/.obsidian/obsidian.conf
        echo "(Required) RPC User: "
        read user
        echo "rpcuser=$user" >> $config 
        echo "(Required) RPC Password: "
        read password
        echo "rpcpassword=$password" >> $config
        echo "(Optional) Email Address For Wallet Alerts: "
        read email
        echo "alertnotify=echo %s | mail -s 'Obsidian Alert' $email" >> $config
}

#################################################################
# Update Ubuntu and install prerequisites for running Obsidian  #
#################################################################
sudo apt-get update
#################################################################
# Build Obsidian from source                                    #
#################################################################
NPROC=$(nproc)
echo "nproc: $NPROC"
#################################################################
# Install all necessary packages for building Obsidian          #
#################################################################
sudo apt-get install -y qt4-qmake libqt4-dev libminiupnpc-dev libdb++-dev libdb-dev libcrypto++-dev libqrencode-dev libboost-all-dev build-essential libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libssl-dev ufw git
sudo add-apt-repository -y ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install -y libdb4.8-dev libdb4.8++-dev
wget https://download.libsodium.org/libsodium/releases/LATEST.tar.gz 
tar -xvzf LATEST.tar.gz 
cd libsodium* 
./configure 
make
make check 
sudo make install 
sudo ldconfig
sudo apt-get install -y libsodium
cd ..
cleandeps
init
build
