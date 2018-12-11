QualityAir

Casos de Teste de Unidade - Simulador

Histórico da Revisão

| Data       | **Versão** | **Descrição**     | **Autor**         |
| ---------- | ---------- | ----------------- | ----------------- |
| 09/12/2018 | 1.0        | Primeiro rascunho | João André Pestre |
|            |            |                   |                   |
|            |            |                   |                   |
|            |            |                   |                   |
|            |            |                   |                   |
|            |            |                   |                   |
|            |            |                   |                   |
|            |            |                   |                   |

#   
Identificação

Testes de Integração entre Backend e Broker

1.  # Informações Sobre os Stubs 
    
    1.  Stub 1:
        
        1.  *Nome:* enviar\_mensagem\_ao\_broker()
        
        2.  *Objetivo:* Emular dados enviados através do Broker.
        
        3.  *Retorno:* 1 caso for enviado; 0 caso não.
    
    2.  Stub 2:
        
        4.  *Nome:* criar\_mensagem()
        
        5.  *Objetivo:* Emular mensagem a ser enviada ao Broker.
        
        6.  *Retorno:* Mensagem mockada

2.  # Casos de Teste
    
    3.  ## Caso de Teste 1: Receber mensagem do Broker
        
        7.  ### Descrição

Testar recepção de mensagens do Broker pelo Backend.

### Pré-condições para o caso

Broker configurado

Appsettings.json configurado

9.  ### Identificação das Unidades/Classes Envolvidas
    
    1.  Backend
        
        1.  > BrokerCommunicationController
        
        2.  > MQTTClient
        
        3.  > MQTTMsgBase
    
    2.  ### Broker

10. ### Conjunto de valores

<table>
<thead>
<tr class="header">
<th><strong>Conjunto de Valores</strong></th>
<th></th>
<th></th>
<th></th>
<th></th>
<th></th>
<th></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td></td>
<td>Cenário 1</td>
<td>Cenário 2</td>
<td>Cenário 3</td>
<td>Cenário 4</td>
<td>Cenário 5</td>
<td>Cenário 6</td>
</tr>
<tr class="even">
<td><strong>Nome do Host</strong></td>
<td>Nome correto</td>
<td>Nome incorreto</td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome correto</td>
</tr>
<tr class="odd">
<td><strong>Username</strong></td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome incorreto</td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome correto</td>
</tr>
<tr class="even">
<td><strong>Senha</strong></td>
<td>Senha correto</td>
<td>Senha correto</td>
<td>Senha correto</td>
<td>Senha incorreto</td>
<td>Senha correto</td>
<td>Senha correto</td>
</tr>
<tr class="odd">
<td><strong>Porta</strong></td>
<td>Porta correta</td>
<td>Porta correta</td>
<td>Porta correta</td>
<td>Porta correta</td>
<td>Porta incorreta</td>
<td>Porta correta</td>
</tr>
<tr class="even">
<td><strong>Tópico</strong></td>
<td>Tópico correto</td>
<td>Tópico correto</td>
<td>Tópico correto</td>
<td>Tópico correto</td>
<td>Tópico correto</td>
<td>Tópico incorreto</td>
</tr>
<tr class="odd">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Mensagem recebida</td>
<td>Mensagem não recebida</td>
<td>Mensagem não recebida</td>
<td>Mensagem não recebida</td>
<td>Mensagem não recebida</td>
<td>Mensagem não recebida</td>
</tr>
<tr class="even">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><strong>Sucesso / Falha</strong></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><p><strong>Nº Ambiente </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><p><strong>Nº Log </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

4.  ## Caso de Teste 2: Publicar mensagens recebidas do Broker
    
    11. ### Descrição

Testar publicação de mensagens recebidas do Broker pelo Backend.

### Pré-condições para o caso

Broker configurado

Appsettings.json configurado

13. ### Identificação das Unidades/Classes Envolvidas
    
    3.  Backend
        
        4.  > BrokerCommunicationController
        
        5.  > DataTransformation
        
        6.  > JSONBrokerMessage
        
        7.  > MQTTMsgPublishEventArgs
    
    4.  ### Broker

14. ### Conjunto de valores

<table>
<thead>
<tr class="header">
<th><strong>Conjunto de Valores</strong></th>
<th></th>
<th></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td></td>
<td>Cenário 1</td>
<td>Cenário 2</td>
</tr>
<tr class="even">
<td><strong>Mensagem</strong></td>
<td>Dentro do formato JSON</td>
<td>Nome incorreto</td>
</tr>
<tr class="odd">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Objeto JSON</td>
<td>JSON não enviado</td>
</tr>
<tr class="even">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><strong>Sucesso / Falha</strong></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><p><strong>Nº Ambiente </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><p><strong>Nº Log </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

5.  ## Caso de Teste 3: Comparar mensagens enviadas pelo Broker
    
    15. ### Descrição

Testar comparação de mensagens enviadas pelo Broker ao Backend.

### Pré-condições para o caso

Broker configurado

Appsettings.json configurado

17. ### Identificação das Unidades/Classes Envolvidas
    
    5.  Backend
        
        8.  > BrokerCommunicationController
        
        9.  > DataTransferObject
    
    6.  ### Broker

18. ### Conjunto de valores

<table>
<thead>
<tr class="header">
<th><strong>Conjunto de Valores</strong></th>
<th></th>
<th></th>
<th></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td></td>
<td>Cenário 1</td>
<td>Cenário 2</td>
<td></td>
</tr>
<tr class="even">
<td><strong>Mensagem do Broker</strong></td>
<td>Mensagem existente</td>
<td>Mensagem nula</td>
<td>Mensagem existente</td>
</tr>
<tr class="odd">
<td><strong>Mensagem Antiga do Broker</strong></td>
<td>Mensagem existente</td>
<td>Mensagem existente</td>
<td>Mensagem nula</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td><em>true</em> se as mensagens forem diferentes</td>
<td><em>true</em></td>
<td>Comparação não é feita</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso / Falha</strong></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><p><strong>Nº Ambiente </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><p><strong>Nº Log </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>
