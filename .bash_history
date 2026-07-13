sudo apt update
sudo apt install openssh-server
ssh-keygen -t rsa -p ""
cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys
chmod 600 ~/,ssh/authorized_keys
chmod 600 ~/.ssh/authorized_keys
ssh localhost
ls /usr/local/
readlink -f $(which java)
nano $HADOOP_HOME/etc/hadoop/hadoop-env.sh
hadoop version
nano $HADOOP_HOME/etc/hadoop/core-site.xml
nano $HADOOP_HOME/etc/hadoop/hdfs-site.xml
mkdir -p/usr/local/hadoop/hdfs/namenode
mkdir -p /usr/local/hadoop/hdfs/namenode
mkdir -p /usr/local/hadoop/hdfs/datanode
sudo chown -R $USER:$USER /usr/local/hadoop/hdfs
cp $HADOOP_HOME/etc/hadoop/mapred-site.xml.template $HADOOP_HOME/etc/hadoop/mapred-site.xml
ls $HADOOP_HOME/etc/hadoop/
nano $HADOOP_HOME/etc/hadoop/mapred-site.xml
nano $HADOOP_HOME/etc/hadoop/yarn-site.xml
sudo apt install ssh -y
ssh-keygen -t rsa -P ""
cat  ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys
chmod 600 ~/.ssh/authorized_keys
ssh localhost
hdfs namenode -format
start-dfs.sh
nano $HADOOP_HOME/etc/hadoop/hadoop-env.sh
cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys
hdfs namenodee -format
hdfs namenode -format
start-dfs.sh
start-yarn.sh
jps
cd $HADOOP_HOME/sbin
chmod +x start-dfs.sh
chmod +x start-yarn.sh
cd ..
cd ~
cd ..
start-dfs.sh
cd
cd ~/Desktop
start-dfs.sh
./start-dfs.sh
ls -l start-dfs.sh
CCCLEAR
CLEAR
clear
start-dfs.sh
cd $HADOOP_HOME/sbin
chmod -R +x $HADOOP_HOME
./start-dfs.sh
sudo bash start-dfs.sh
ssh localhost
cd $HADOOP_HOME/sbin
./start-dfs.sh
ssh-keygen -t rsa
sudo apt update
sudo apt upgrade -y
sudo apt install ubuntu-desktop
sudo reboot
ps --l
PS --help
ps
-h
ps -h
ps --man
man ps
ps -aux
cat
ps
ps -aux
man ps
cat /proc
ps
ps -aux
cat > file_name
cat > usha.txt
start-all.sh
jps
hdfs dfs -mkdir -p /fraud_input
hdfs dfs -put /home/usha/Desktop/Lab_Session/transaction.txt
hdfs dfs -mkdir -p /fraud_input
start-all.sh
jps
hdfs dfs -ls /
hdfs dfs -mkdir -p /user/hadoop
mkdir -p ~/ca_house_price_mr/{src,data,scripts,output}
cd ~/ca_house_price_mr
find . -type d
nano ~/ca_house_price_mr/data/generate_data.py
cd ~/ca_house_price_mr
python3 data/generate_data.py
head -5 data/california_housing.csv
hdfs dfs -mkdir -p /user/hadoop/ca_housing/input
hdfs dfs -put ~/ca_house_price_mr/data/california_housing.csv     /user/hadoop/ca_housing/input/
hdfs dfs -put ~/ca_house_price_mr/data/california_housing.csv     /user/hadoop/california_housing/input/
jps
pwd
hdfs dfs -put data/california_housing.csv     /user/hadoop/california_housing/input/
stop-all.s
stop-all.sh
hdfs namenode -format
start-all.sh
jps
hdfs dfs -ls /
hdfs dfs -mkdir -p /user/hadoop
mkdir -p ~/ca_house_price_mr/{src,data,scripts,output}
cd ~/ca_house_price_mr
find . -type d
nano ~/ca_house_price_mr/data/generate_data.py
y
cd ~/ca_house_price_mr
python3 data/generate_data.py
head -5 data/california_housing.csv
hdfs dfs -mkdir -p /user/hadoop/ca_housing/input
hdfs dfs -put data/california_housing.csv     /user/hadoop/ca_housing/input/
jps
cd ~/../../usr/local/hadoop/hdfs
rm -rf datanode
mkdir datanode
ls
stop-all.sh
hdfs datanode -format
start-all.sh
jps
ls
stop-all.sh
ls
rm -rf datanode
ls
mkdir datanode
hdfs datanode -format
jps
start-all.sh
jps
stop-all.sh
