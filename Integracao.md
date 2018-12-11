QualityAir

Casos de Teste de Unidade - Simulador

Histórico da Revisão

  Data         **Versão**   **Descrição**       **Autor**
  ------------ ------------ ------------------- -------------------
  09/12/2018   1.0          Primeiro rascunho   João André Pestre
                                                
                                                
                                                
                                                
                                                
                                                
                                                

 Identificação
=============

Testes de Integração entre Backend e Broker

1.  Informações Sobre os Stubs 
    ===========================

    1.  Stub 1:

        1.  *Nome:* enviar\_mensagem\_ao\_broker()

        2.  *Objetivo:* Emular dados enviados através do Broker.

        3.  *Retorno:* 1 caso for enviado; 0 caso não.

    2.  Stub 2:

        4.  *Nome:* criar\_mensagem()

        5.  *Objetivo:* Emular mensagem a ser enviada ao Broker.

        6.  *Retorno:* Mensagem mockada

2.  Casos de Teste
    ==============

    3.  Caso de Teste 1: Receber mensagem do Broker
        -------------------------------------------

        7.  ### Descrição

Testar recepção de mensagens do Broker pelo Backend.

### Pré-condições para o caso

Broker configurado

Appsettings.json configurado

9.  ### Identificação das Unidades/Classes Envolvidas

    1.  Backend

        1.  BrokerCommunicationController

        2.  MQTTClient

        3.  MQTTMsgBase

    2.  ### Broker

10. ### Conjunto de valores

+---------+---------+---------+---------+---------+---------+---------+
| **Conju |         |         |         |         |         |         |
| nto     |         |         |         |         |         |         |
| de      |         |         |         |         |         |         |
| Valores |         |         |         |         |         |         |
| **      |         |         |         |         |         |         |
+=========+=========+=========+=========+=========+=========+=========+
|         | Cenário | Cenário | Cenário | Cenário | Cenário | Cenário |
|         | 1       | 2       | 3       | 4       | 5       | 6       |
+---------+---------+---------+---------+---------+---------+---------+
| **Nome  | Nome    | Nome    | Nome    | Nome    | Nome    | Nome    |
| do      | correto | incorre | correto | correto | correto | correto |
| Host**  |         | to      |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Usern | Nome    | Nome    | Nome    | Nome    | Nome    | Nome    |
| ame**   | correto | correto | incorre | correto | correto | correto |
|         |         |         | to      |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Senha | Senha   | Senha   | Senha   | Senha   | Senha   | Senha   |
| **      | correto | correto | correto | incorre | correto | correto |
|         |         |         |         | to      |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Porta | Porta   | Porta   | Porta   | Porta   | Porta   | Porta   |
| **      | correta | correta | correta | correta | incorre | correta |
|         |         |         |         |         | ta      |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Tópic | Tópico  | Tópico  | Tópico  | Tópico  | Tópico  | Tópico  |
| o**     | correto | correto | correto | correto | correto | incorre |
|         |         |         |         |         |         | to      |
+---------+---------+---------+---------+---------+---------+---------+
| **Valor | Mensage | Mensage | Mensage | Mensage | Mensage | Mensage |
| de      | m       | m       | m       | m       | m       | m       |
| saída   | recebid | não     | não     | não     | não     | não     |
| (Result | a       | recebid | recebid | recebid | recebid | recebid |
| ado     |         | a       | a       | a       | a       | a       |
| Esperad |         |         |         |         |         |         |
| o)**    |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Resul |         |         |         |         |         |         |
| tado    |         |         |         |         |         |         |
| Obtido* |         |         |         |         |         |         |
| *       |         |         |         |         |         |         |
|         |         |         |         |         |         |         |
| (se     |         |         |         |         |         |         |
| diferen |         |         |         |         |         |         |
| te      |         |         |         |         |         |         |
| do      |         |         |         |         |         |         |
| esperad |         |         |         |         |         |         |
| o)      |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Suces |         |         |         |         |         |         |
| so      |         |         |         |         |         |         |
| /       |         |         |         |         |         |         |
| Falha** |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Nº    |         |         |         |         |         |         |
| Ambient |         |         |         |         |         |         |
| e       |         |         |         |         |         |         |
| **      |         |         |         |         |         |         |
|         |         |         |         |         |         |         |
| **(se   |         |         |         |         |         |         |
| falha)* |         |         |         |         |         |         |
| *       |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
| **Nº    |         |         |         |         |         |         |
| Log **  |         |         |         |         |         |         |
|         |         |         |         |         |         |         |
| **(se   |         |         |         |         |         |         |
| falha)* |         |         |         |         |         |         |
| *       |         |         |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+

4.  Caso de Teste 2: Publicar mensagens recebidas do Broker
    -------------------------------------------------------

    11. ### Descrição

Testar publicação de mensagens recebidas do Broker pelo Backend.

### Pré-condições para o caso

Broker configurado

Appsettings.json configurado

13. ### Identificação das Unidades/Classes Envolvidas

    3.  Backend

        4.  BrokerCommunicationController

        5.  DataTransformation

        6.  JSONBrokerMessage

        7.  MQTTMsgPublishEventArgs

    4.  ### Broker

14. ### Conjunto de valores

+-----------------------+-----------------------+-----------------------+
| **Conjunto de         |                       |                       |
| Valores**             |                       |                       |
+=======================+=======================+=======================+
|                       | Cenário 1             | Cenário 2             |
+-----------------------+-----------------------+-----------------------+
| **Mensagem**          | Dentro do formato     | Nome incorreto        |
|                       | JSON                  |                       |
+-----------------------+-----------------------+-----------------------+
| **Valor de saída      | Objeto JSON           | JSON não enviado      |
| (Resultado            |                       |                       |
| Esperado)**           |                       |                       |
+-----------------------+-----------------------+-----------------------+
| **Resultado Obtido**  |                       |                       |
|                       |                       |                       |
| (se diferente do      |                       |                       |
| esperado)             |                       |                       |
+-----------------------+-----------------------+-----------------------+
| **Sucesso / Falha**   |                       |                       |
+-----------------------+-----------------------+-----------------------+
| **Nº Ambiente **      |                       |                       |
|                       |                       |                       |
| **(se falha)**        |                       |                       |
+-----------------------+-----------------------+-----------------------+
| **Nº Log **           |                       |                       |
|                       |                       |                       |
| **(se falha)**        |                       |                       |
+-----------------------+-----------------------+-----------------------+

5.  Caso de Teste 3: Comparar mensagens enviadas pelo Broker
    --------------------------------------------------------

    15. ### Descrição

Testar comparação de mensagens enviadas pelo Broker ao Backend.

### Pré-condições para o caso

Broker configurado

Appsettings.json configurado

17. ### Identificação das Unidades/Classes Envolvidas

    5.  Backend

        8.  BrokerCommunicationController

        9.  DataTransferObject

    6.  ### Broker

18. ### Conjunto de valores

+-----------------+-----------------+-----------------+-----------------+
| **Conjunto de   |                 |                 |                 |
| Valores**       |                 |                 |                 |
+=================+=================+=================+=================+
|                 | Cenário 1       | Cenário 2       |                 |
+-----------------+-----------------+-----------------+-----------------+
| **Mensagem do   | Mensagem        | Mensagem nula   | Mensagem        |
| Broker**        | existente       |                 | existente       |
+-----------------+-----------------+-----------------+-----------------+
| **Mensagem      | Mensagem        | Mensagem        | Mensagem nula   |
| Antiga do       | existente       | existente       |                 |
| Broker**        |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
| **Valor de      | *true* se as    | *true*          | Comparação não  |
| saída           | mensagens forem |                 | é feita         |
| (Resultado      | diferentes      |                 |                 |
| Esperado)**     |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
| **Resultado     |                 |                 |                 |
| Obtido**        |                 |                 |                 |
|                 |                 |                 |                 |
| (se diferente   |                 |                 |                 |
| do esperado)    |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
| **Sucesso /     |                 |                 |                 |
| Falha**         |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
| **Nº Ambiente   |                 |                 |                 |
| **              |                 |                 |                 |
|                 |                 |                 |                 |
| **(se falha)**  |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
| **Nº Log **     |                 |                 |                 |
|                 |                 |                 |                 |
| **(se falha)**  |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
