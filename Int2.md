QualityAir

Casos de Teste de Integração - Backend/Repositório

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
        
        1.  *Nome:* receber\_dados\_do\_broker()
        
        2.  *Objetivo:* Emular dados recebidos através do Broker.
        
        3.  *Retorno:* Mensagem JSON

2.  # Casos de Teste
    
    2.  ## Caso de Teste 1: Backend escrever dados no repositório
        
        4.  ### Descrição

Testar escrita de dados no repositório por parte do backend.

### Pré-condições para o caso

Mensagem lida do broker

Conexão com o repositório de dados estabelecida

6.  ### Identificação das Unidades/Classes Envolvidas
    
    1.  Backend
        
        1.  BrokerCommunicationController
        
        2.  > QualityAirDBContext
        
        3.  > Measurement
        
        4.  > PhysicalMeasure
        
        5.  > Sensor
        
        6.  > Su
    
    2.  ### Repositório

7.  ### Conjunto de valores

<table>
<thead>
<tr class="header">
<th><strong>Conjunto de Valores</strong></th>
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
</tr>
<tr class="even">
<td><strong>Latitude no objeto JSON</strong></td>
<td>Latitude de uma US registrada no repositório</td>
<td>Latitude de uma US registrada no repositório</td>
<td>Latitude de uma US registrada no repositório</td>
<td>Latitude de uma US não registrada no repositório</td>
</tr>
<tr class="odd">
<td><strong>Longitude no objeto JSON</strong></td>
<td>Longitude de uma US registrada no repositório</td>
<td>Longitude de uma US registrada no repositório</td>
<td>Longitude de uma US não registrada no repositório</td>
<td>Longitude de uma US registrada no repositório</td>
</tr>
<tr class="even">
<td><strong>PhysicalQuantity no objeto JSON</strong></td>
<td>Grandeza de uma Medida registrada no repositório</td>
<td>Grandeza de uma Medida não registrada no repositório</td>
<td>Grandeza de uma Medida registrada no repositório</td>
<td>Grandeza de uma Medida registrada no repositório</td>
</tr>
<tr class="odd">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Nova Measurement registrada no repositório</td>
<td>Exceção SQL, falta de FK</td>
<td>Exceção SQL, falta de FK</td>
<td>Exceção SQL, falta de FK</td>
</tr>
<tr class="even">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><strong>Sucesso/Falha</strong></td>
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
</tr>
<tr class="odd">
<td><p><strong>Nº Log </strong></p>
<p><strong>(se falha)</strong></p></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

3.  ## Caso de Teste 2: Backend ler dados do repositório - Página Index
    
    8.  ### Descrição

Testar leitura de dados do repositório pelo backend após pedido pela
página index.

### Pré-condições para o caso

Pedido do visualizador recebido pelo backend

Conexão com o repositório de dados já estabelecida

10. ### Identificação das Unidades/Classes Envolvidas
    
    3.  *Backend*
        
        7.  DashboardController
        
        8.  QualityAirDBContext
        
        9.  Neighborhood
        
        10. Su
    
    4.  ### Repositório

11. ### Conjunto de valores

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
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela sem dados</td>
</tr>
<tr class="odd">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Lista de bairros obtida</td>
<td>Lista de bairros não obtida</td>
</tr>
<tr class="even">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><strong>Sucesso/Falha</strong></td>
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

## 

4.  ## Caso de Teste 3: Backend ler dados mais recentes de um bairro específico do repositório - Página latest/Neighborhood
    
    12. ### Descrição

Testar leitura de dados mais recentes de um bairro do repositório pelo
backend após pedido pela página Neighborhood.

### Pré-condições para o caso

Pedido do visualizador recebido pelo backend

Conexão com o repositório de dados já estabelecida

14. ### Identificação das Unidades/Classes Envolvidas
    
    5.  > *Backend*
        
        11. > DashboardController
        
        12. > QualityAirDBContext
        
        13. > Measurement
        
        14. > PhysicalMeasure
        
        15. > Neighborhood
        
        16. > Sensor
        
        17. > Su
    
    6.  ### Repositório

15. ### Conjunto de valores

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
<td>Cenário 7</td>
</tr>
<tr class="even">
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela sem dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>Tabela SU</strong></td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU não registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
</tr>
<tr class="even">
<td><strong>Tabela Sensor</strong></td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor não existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
</tr>
<tr class="odd">
<td><strong>Tabela PhysicalMeasure</strong></td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza não existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
</tr>
<tr class="even">
<td><strong>Tabela Measurement</strong></td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida não existente</td>
<td>Medida existente</td>
</tr>
<tr class="odd">
<td><strong>NeighborhoodID</strong></td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID não registrado</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Medidas referentes ao bairro correto &amp; Lista de Bairros</td>
<td>Lista de bairros e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida, bairro específico e medidas não serão obtidas</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso/Falha</strong></td>
<td></td>
<td></td>
<td></td>
<td></td>
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
<td></td>
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
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

5.  ## Caso de Teste 4: Backend exportar dados - Página ExportData
    
    16. ### Descrição

Testar leitura de todos os dados do Repositório após pedido pela página
ExportData.

### Pré-condições para o caso

Pedido do visualizador recebido pelo backend

Conexão com o repositório de dados já estabelecida

18. ### Identificação das Unidades/Classes Envolvidas
    
    7.  > *Backend*
        
        18. > DashboardController
        
        19. > QualityAirDBContext
        
        20. > Measurement
        
        21. > PhysicalMeasure
        
        22. > Neighborhood
        
        23. > Sensor
        
        24. > Su
    
    8.  ### Repositório

19. ### Conjunto de valores

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
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela sem dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>Tabela SU</strong></td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU não registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
</tr>
<tr class="even">
<td><strong>Tabela Sensor</strong></td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor não existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
</tr>
<tr class="odd">
<td><strong>Tabela PhysicalMeasure</strong></td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza não existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
</tr>
<tr class="even">
<td><strong>Tabela Measurement</strong></td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida não existente</td>
</tr>
<tr class="odd">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Medidas referentes ao bairro correto &amp; Lista de Bairros</td>
<td>Lista de bairros e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
<td>Lista de bairros obtida e medidas não obtidas</td>
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
<td><strong>Sucesso/Falha</strong></td>
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

6.  ## Caso de Teste 5: Backend exportar dados filtrados - Página ExportFilteredData
    
    20. ### Descrição

Testar leitura de dados filtrados do Repositório após pedido pela página
ExportFilteredData.

### Pré-condições para o caso

Pedido do visualizador recebido pelo backend

Conexão com o repositório de dados já estabelecida

22. ### Identificação das Unidades/Classes Envolvidas
    
    9.  > *Backend*
        
        25. > DashboardController
        
        26. > QualityAirDBContext
        
        27. > Measurement
        
        28. > PhysicalMeasure
        
        29. > Neighborhood
        
        30. > Sensor
        
        31. > Su
    
    10. ### Repositório

23. ### Conjunto de valores

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
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela sem dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>Tabela SU</strong></td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU não registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
</tr>
<tr class="even">
<td><strong>Tabela Sensor</strong></td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor não existente na SU</td>
<td>Sensor existente na SU</td>
</tr>
<tr class="odd">
<td><strong>Tabela PhysicalMeasure</strong></td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza não existente no Sensor</td>
</tr>
<tr class="even">
<td><strong>Tabela Measurement</strong></td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
</tr>
<tr class="odd">
<td><strong>NeighborhoodID</strong></td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
</tr>
<tr class="even">
<td><strong>PhysicalQuantity</strong></td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
</tr>
<tr class="odd">
<td><strong>Datahora</strong></td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Medidas referentes ao bairro correto</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso/Falha</strong></td>
<td></td>
<td></td>
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
<td></td>
<td></td>
</tr>
<tr class="even">
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
<td>Cenário 6</td>
<td>Cenário 7</td>
<td>Cenário 8</td>
<td>Cenário 9</td>
<td>Cenário 10</td>
<td>Cenário 11</td>
</tr>
<tr class="even">
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>Tabela SU</strong></td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
</tr>
<tr class="even">
<td><strong>Tabela Sensor</strong></td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
</tr>
<tr class="odd">
<td><strong>Tabela PhysicalMeasure</strong></td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
</tr>
<tr class="even">
<td><strong>Tabela Measurement</strong></td>
<td>Medida não existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
</tr>
<tr class="odd">
<td><strong>NeighborhoodID</strong></td>
<td>ID registrado</td>
<td>ID não registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
</tr>
<tr class="even">
<td><strong>PhysicalQuantity</strong></td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza incompatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
</tr>
<tr class="odd">
<td><strong>Datahora</strong></td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora não padronizada</td>
<td>Datahora fora dos limites</td>
<td>Datahora inexistente no repositório</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso/Falha</strong></td>
<td></td>
<td></td>
<td></td>
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
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

7.  ## Caso de Teste 6: Backend exportar gráfico - Página Graph
    
    24. ### Descrição

Testar leitura de dados filtrados do Repositório após pedido pela página
Graph.

### Pré-condições para o caso

Pedido do visualizador recebido pelo backend

Conexão com o repositório de dados já estabelecida

26. ### Identificação das Unidades/Classes Envolvidas
    
    11. > *Backend*
        
        32. > DashboardController
        
        33. > QualityAirDBContext
        
        34. > Measurement
        
        35. > PhysicalMeasure
        
        36. > Neighborhood
        
        37. > Sensor
        
        38. > Su
    
    12. ### Repositório

27. ### Conjunto de valores

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
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela sem dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>Tabela SU</strong></td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU não registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
</tr>
<tr class="even">
<td><strong>Tabela Sensor</strong></td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor não existente na SU</td>
<td>Sensor existente na SU</td>
</tr>
<tr class="odd">
<td><strong>Tabela PhysicalMeasure</strong></td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza não existente no Sensor</td>
</tr>
<tr class="even">
<td><strong>Tabela Measurement</strong></td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
</tr>
<tr class="odd">
<td><strong>NeighborhoodID</strong></td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
</tr>
<tr class="even">
<td><strong>PhysicalQuantity</strong></td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
</tr>
<tr class="odd">
<td><strong>Datahora</strong></td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Medidas referentes ao bairro correto</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso/Falha</strong></td>
<td></td>
<td></td>
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
<td></td>
<td></td>
</tr>
<tr class="even">
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
<td>Cenário 6</td>
<td>Cenário 7</td>
<td>Cenário 8</td>
<td>Cenário 9</td>
<td>Cenário 10</td>
<td>Cenário 11</td>
</tr>
<tr class="even">
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>Tabela SU</strong></td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
<td>SU registrada no bairro</td>
</tr>
<tr class="even">
<td><strong>Tabela Sensor</strong></td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
<td>Sensor existente na SU</td>
</tr>
<tr class="odd">
<td><strong>Tabela PhysicalMeasure</strong></td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
<td>Grandeza existente no Sensor</td>
</tr>
<tr class="even">
<td><strong>Tabela Measurement</strong></td>
<td>Medida não existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
<td>Medida existente</td>
</tr>
<tr class="odd">
<td><strong>NeighborhoodID</strong></td>
<td>ID registrado</td>
<td>ID não registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
<td>ID registrado</td>
</tr>
<tr class="even">
<td><strong>PhysicalQuantity</strong></td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza incompatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
<td>Grandeza compatível</td>
</tr>
<tr class="odd">
<td><strong>Datahora</strong></td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora padronizada, dentro dos limites e existente</td>
<td>Datahora não padronizada</td>
<td>Datahora fora dos limites</td>
<td>Datahora inexistente no repositório</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
<td>Medidas não obtidas</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso/Falha</strong></td>
<td></td>
<td></td>
<td></td>
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
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

8.  ## Caso de Teste 7: Backend ler dados do repositório - Página Neighborhood
    
    28. ### Descrição

Testar leitura de bairros do repositório pelo backend após pedido pela
página Neighborhood.

### Pré-condições para o caso

Pedido do visualizador recebido pelo backend

Conexão com o repositório de dados já estabelecida

30. ### Identificação das Unidades/Classes Envolvidas
    
    13. *Backend*
        
        39. DashboardController
        
        40. QualityAirDBContext
        
        41. Neighborhood
    
    14. ### Repositório

31. ### Conjunto de valores

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
<td>Cenário 3</td>
</tr>
<tr class="even">
<td><strong>Tabela Neighborhood</strong></td>
<td>Tabela com dados</td>
<td>Tabela sem dados</td>
<td>Tabela com dados</td>
</tr>
<tr class="odd">
<td><strong>NeighborhoodID</strong></td>
<td>Bairro existente</td>
<td>Bairro existente</td>
<td>Bairro inexistente</td>
</tr>
<tr class="even">
<td><strong>Valor de saída (Resultado Esperado)</strong></td>
<td>Lista de bairros e nome do bairro</td>
<td>Lista de bairros e nome do bairro não obtidos</td>
<td>Lista de bairros obtida; nome do bairro não obtido</td>
</tr>
<tr class="odd">
<td><p><strong>Resultado Obtido</strong></p>
<p>(se diferente do esperado)</p></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>Sucesso/Falha</strong></td>
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

##
