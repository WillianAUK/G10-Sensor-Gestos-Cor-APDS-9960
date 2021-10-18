<p align="center">
  <a href="https://github.com/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960/issues"><img alt="GitHub issues" src="https://img.shields.io/github/issues/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960"></a>
  <a href="https://github.com/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960/network"><img alt="GitHub forks" src="https://img.shields.io/github/forks/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960"></a>
  <a href="https://github.com/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960/stargazers"><img alt="GitHub stars" src="https://img.shields.io/github/stars/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960"></a>
  <a href="https://github.com/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960/blob/main/LICENSE"><img alt="GitHub license" src="https://img.shields.io/github/license/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960"></a>
  <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960">
  <img alt="Repository size" src="https://img.shields.io/github/repo-size/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960">
  <a href="https://github.com/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960/commits/master">
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/WillianAUK/G10-Sensor-Gestos-Cor-APDS-9960">
  </a>
</p>

<h1 align="center">
    <img alt="Gcontrol" title="#Gcontrol" src="./docs/banner.jpg" width="500px"/>
</h1>

<h4 align="center"> 
	🚧  Gcontrol ⏯️ Em construção ⚠️ 🚧
</h4>

<p align="center">
 <a href="#-sobre-o-projeto">Sobre</a> •
 <a href="Setup">Setup</a> •
 <a href="Funcionalidades">Funcionalidades</a> •
 <a href="Contribuidores">Contribuidores</a> • 
 <a href="Licença">Licença</a>
</p>

## 💻 Sobre o projeto

⏯️ Gcontrol - é uma forma de acionar os controles de mídia por meio gestos identificados pelo sensor APDS-9960 


Projeto desenvolvido durante a disciplina de **Sistemas embarcados** ofertada pelo [IFPB - Campina Grande](https://www.ifpb.edu.br/campinagrande).
A disciplina faz parte do 9º semestre da grade currícular do curso de Engenharia de Computação do IFPB - Campina Grande e tem como responsável o professor [Dr. Alexandre Sales Vasconselos](http://lattes.cnpq.br/8740952344021265), que está ministrando-a no semestre 2021.1

Para videos demonstrativos e arquivos extras, acesse o o drive https://drive.google.com/drive/folders/1uk8sIaNC5tyi2TA3CVgvFQiCZkxG33-y?usp=sharing.

### Simulação

<table>
  <tr>
    <td align="center"><img style="border-radius: 50%;" src="./docs/Imagens/simulation/python_serial_listener.PNG" width="500px;" /><br /><sub><b>Execução do script de comunicação Serial do S.O. com o arduino em Python </b></sub></a><br /> </td>
    <td align="center"><img src="./docs/Imagens/simulation/media_player.PNG" width="500px;" /><br /><sub><b>Software de reprodução de mídia, utilizado como exemplo no projeto</b></sub></a><br /></td>
  </tr>
  <tr>
     <td colspan="2" align="center"><img style="border-radius: 50%;" src="./docs/Imagens/simulation/arduino_proteus.PNG" width="1000px;" /><br /><sub><b>Circuito simulado no proteus</b></sub></a><br /></a></td>
  </tr>
</table>

---

## ✔️ Setup

Para obter uma cópia local instalada e funcionando, siga estas etapas simples de exemplo.

### Pré requisitos

You need Python 3.5 or later to run mypy.  You can have multiple Python
versions (2.x and 3.x) installed on the same system without problems.

Você precisa do Python 3.5 ou posterior para executar o Gcontrol. Você pode ter várias versões do Python (2.xe 3.x) instaladas no mesmo sistema sem problemas.

No Ubuntu, Mint e Debian, você pode instalar o Python 3 assim:

    $ sudo apt-get install python3 python3-pip

Para outros tipos de Linux, macOS e Windows, os pacotes estão disponíveis em

  https://www.python.org/getit/

### Instalações

1. Atualize o pip do Python
   ```sh
   python -m pip install --upgrade pip --user
   ```
2. Instale o PySerial atráves do seguinte link ou comando [PySerial](https://pythonhosted.org/pyserial/pyserial.html#installation)
   ```sh
   python -m pip install pyserial
   ```
3. Instale o PyAutoGui atrábes do seguinte link ou comando [PyAutoGui](https://pyautogui.readthedocs.io/en/latest/install.html)
   ```sh
   python -m pip install pyautogui 
   ```
4. Rode o seguinte script Python [Gcontrol_listener](./firmware/media_control/media_control.py)
5. Rode o seguinte script Arduino, com as devidas adequações a sua implementação [Gcontrol_Arduino](./firmware/controller_media/controller_media.ino)
6. Fim

<p align="right">(<a href="#top">back to top</a>)</p>

## ⚙️ Funcionalidades

- [x] Conexão do hardwaare embarcado com software de reprodução de mídias
  - [x] Implementar os protocolos de comunicação
  
- [x] Os usuários tem acesso ao sistema integrado, onde podem por meio de gestos específicos:
  - [x] Pausar 
  - [x] Despausar
  - [x] Avançar
  - [x] Retroceder 
  - [x] Aumentar volume
  - [x] Diminuir volume

---

## 👨‍💻 Desenvolvedores

<table>
  <tr>
    <td align="center"><a href="https://github.com/WillianAUK"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/71937155?v=4" width="100px;" alt=""/><br /><sub><b>Willian Adriano</b></sub></a><br /><a href="https://github.com/WillianAUK" title="Willian">👨‍🚀</a></td>
    <td align="center"><a href="https://github.com/JardelBrandon"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/25730081?v=4" width="100px;" alt=""/><br /><sub><b>Jardel Brandon</b></sub></a><br /><a href="https://github.com/JardelBrandon" title="Jardel">👨‍🚀</a></td>
    <td align="center"><a href="https://github.com/kvalhomanu"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/32714498?v=4" width="100px;" alt=""/><br /><sub><b>Marcelo Carvalho</b></sub></a><br /><a href="https://github.com/kvalhomanu" title="Marcelo">👨‍🚀</a></td>
  </tr>
</table>

## 💪 Como contribuir para o projeto

1. Faça um **fork** do projeto.
2. Crie uma nova branch com as suas alterações: `git checkout -b my-feature`
3. Salve as alterações e crie uma mensagem de commit contando o que você fez: `git commit -m "feature: My new feature"`
4. Envie as suas alterações: `git push origin my-feature`

---

## 📝 Licença

Este projeto esta sobe a licença [MIT](./LICENSE).

---
