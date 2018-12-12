QualityAir

Casos de Teste de Integração - US/Broker

Histórico da
Revisão

| Data       | **Versão** | **Descrição**     | **Autor**                         |
| ---------- | ---------- | ----------------- | --------------------------------- |
| 08/12/2018 | 1.0        | Primeiro rascunho | João André Pestre, Lucas Santiago |
|            |            |                   |                                   |
|            |            |                   |                                   |
|            |            |                   |                                   |
|            |            |                   |                                   |
|            |            |                   |                                   |
|            |            |                   |                                   |
|            |            |                   |                                   |

#   
Identificação

Testes de Integração entre US e Broker

1.  # Informações Sobre os Stubs 
    
    1.  Stub 1:
        
        1.  *Nome:* coleta\_e\_preparo\_de\_dados().
        
        2.  *Objetivo:* Simular a coleta e a preparação de dados pela
            unidade de sensoriamento para enviar ao broker.
        
        3.  *Retorno:* Mensagem string no formato JSON.

2.  # Casos de Teste
    
    2.  ## Caso de Teste 1: Enviar e receber dados
        
        4.  ### Descrição

Testar envio de dados da unidade de sensoriamento para o broker.

### Pré-condições para o caso

Broker já configurado

US coletando dados

1.  ### Broker

2.  ### US:
    
    1.  > *Classes*:
    
    2.  > US

### Conjunto de valores

<table>
<thead>
<tr class="header">
<th><strong>Conjunto de Valores</strong></th>
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
</tr>
<tr class="even">
<td><strong>Hostname</strong></td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome correto</td>
<td>Nome incorreto</td>
</tr>
<tr class="odd">
<td><strong>Canal da exchange</strong></td>
<td>Canal correto</td>
<td>Canal correto</td>
<td>Canal correto</td>
<td>Canal incorreto</td>
<td>Canal correto</td>
</tr>
<tr class="even">
<td><strong>Login do Broker</strong></td>
<td>Login correto</td>
<td>Login incorreto</td>
<td>Login correto</td>
<td>Login correto</td>
<td>Login correto</td>
</tr>
<tr class="odd">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Dados recebidos pelo broker</td>
<td>Dados não recebidos pelo broker</td>
<td>Dados não recebidos pelo broker</td>
<td>Dados não recebidos pelo broker</td>
<td>Dados não recebidos pelo broker</td>
</tr>
<tr class="even">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
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
</tr>
<tr class="even">
<td><p><strong>Nº Ambiente </strong></p>
<p><strong>(se falha)</strong></p></td>
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
</tr>
</tbody>
</table>
