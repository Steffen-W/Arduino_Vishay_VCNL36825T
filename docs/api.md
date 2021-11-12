# Vishay_VCNL36825T library

## Methods

### `begin()`

Initialize the vcnl36825t.

#### Syntax 

```
vcnl36825t.begin()
```

#### Parameters

None.

#### Returns

1 on success, 0 on failure.

#### Example

```
if (!vcnl36825t.begin()) {
    Serial.println("Failed to initialize vcnl36825t!");
    while (1);
}
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `end()`

De-initialize the vcnl36825t.

#### Syntax 

```
vcnl36825t.end()
```

#### Parameters

None.

#### Returns

None.

#### Example

```
if (!vcnl36825t.begin()) {
    Serial.println("Failed to initialize vcnl36825t!");
    while (1);
}

// Read data...

// Done with the vcnl36825t readings
vcnl36825t.end();
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `read_PS()`

Read the vcnl36825t's Proximity sensor. 

#### Syntax 

```
boolean vcnl36825t.read_PS(uint16_t *ps)
```

#### Parameters

ps - point of uint16_t for proximity count.

#### Returns

true on success, false on failure.

#### Example

```
uint16_t ps;

if (vcnl36825t.read_PS(&ps))
    Serial.print(ps);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `PS_ST()`

Stop Proximity sensor. 

#### Syntax 

```
boolean vcnl36825t.PS_ST(boolean stop)
```

#### Parameters

stop
- **true** to **Stop** sensor
- **false** to **Start** sensor.

#### Returns

true on success, false on failure.

#### Example

```
// Start Proximity sensor
vcnl36825t.PS_ST(false);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `PS_INT()`

Set interrupt mode for Proximity sensor. 

#### Syntax 

```
boolean vcnl36825t.PS_INT(uint16_t ps_int)
```

#### Parameters

ps_int
- **PS_INT_DISABLE** for interrupt disable.
- **PS_INT_LOGICMODE** for logic high / low mode.
- **PS_INT_FIRSTHIGH** for first high.
- **PS_INT_ENABLE** for interrupt enable.

#### Returns

true on success, false on failure.

#### Example

```
// Enable Proximity ensor interrupt
vcnl36825t.PS_INT(vcnl36825t.PS_INT_ENABLE);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `PS_INT_with_threshold()`

Enable Proximity sensor interrupt and set Low and High thresholds. 

#### Syntax 

```
boolean vcnl36825t.PS_INT_with_threshold(uint16_t thdl, uint16_t thdh)
```

#### Parameters

thdl - Low threshold.
thdh - High threshold.

#### Returns

true on success, false on failure.

#### Example

```
// Enable PS interrupt with 50 low threshold and 100 high threshold.
vcnl36825t.PS_INT_with_threshold(50, 100);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `read_INT_FLAG()`

Read to clean interrupt for VCNL36825T.

#### Syntax 

```
boolean vcnl36825t.read_INT_FLAG(uint16_t *int_flag)
```

#### Parameters

int_flag - point of uint16_t, it mixes by:<BR>
- **PS_IF_AWAY** for PS Away event.<BR>
- **PS_IF_CLOSE** for PS Close event.<BR>
- **PS_SPFLAG** for PS enter sunlight protection.<BR>
- **PS_ACFLAG** for after PS finishing auto-calibration.<BR>

#### Returns

true on success, false on failure.

#### Example

```
uint16_t int_flag;
if (vcnl36825t.read_INT_FLAG(&int_flag))
{
  if (int_flag & (vcnl36825t.PS_IF_CLOSE | vcnl36825t.PS_IF_AWAY))
  {
    uint16_t ps;
    vcnl36825t.read_PS(&ps);
    Serial.print("PS = ");
    Serial.print(ps);
    if (int_flag & vcnl36825t.PS_IF_CLOSE)
      Serial.print("\tClose event.");
    if (int_flag & vcnl36825t.PS_IF_AWAY)
      Serial.print("\tAway event.");
    Serial.println();
  }
}
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)


### `set_PS_I_VCSEL()`

Set VCSEL current.

#### Syntax 

```
boolean vcnl36825t.set_PS_I_VCSEL(PS_I_VCSEL_t i_vcsel)
```

#### Parameters

i_vcsel - it mixes by:<BR>
- **PS_I_VCSEL_10mA** 10mA<BR>
- **PS_I_VCSEL_12mA** 12mA<BR>
- **PS_I_VCSEL_14mA** 14mA<BR>
- **PS_I_VCSEL_16mA** 16mA<BR>
- **PS_I_VCSEL_18mA** 18mA<BR>
- **PS_I_VCSEL_20mA** 20mA<BR>

#### Returns

true on success, false on failure.

#### Example

```
  // Set VCSEL to 20mA current
  vcnl36825t.set_PS_I_VCSEL(vcnl36825t.PS_I_VCSEL_10mA));
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `get_PS_I_VCSEL()`

Get the setting of VCSEL current.

#### Syntax 

```
VCNL36825TClass::PS_I_VCSEL_t vcnl36825t.get_PS_I_VCSEL()
```

#### Parameters

None.

#### Returns

- **PS_I_VCSEL_10mA** 10mA<BR>
- **PS_I_VCSEL_12mA** 12mA<BR>
- **PS_I_VCSEL_14mA** 14mA<BR>
- **PS_I_VCSEL_16mA** 16mA<BR>
- **PS_I_VCSEL_18mA** 18mA<BR>
- **PS_I_VCSEL_20mA** 20mA<BR>

#### Example

```
  // Get the VCSEL current
  Serial.print("PS_I_VCSE: ");
  switch(vcnl36825t.get_PS_I_VCSEL())
  {
    case VCNL36825TClass::PS_I_VCSEL_10mA:
      Serial.println("10mA");
      break;
    case VCNL36825TClass::PS_I_VCSEL_12mA:
      Serial.println("12mA");
      break;
    case VCNL36825TClass::PS_I_VCSEL_14mA:
      Serial.println("14mA");
      break;
    case VCNL36825TClass::PS_I_VCSEL_16mA:
      Serial.println("16mA");
      break;
    case VCNL36825TClass::PS_I_VCSEL_18mA:
      Serial.println("18mA");
      break;
    case VCNL36825TClass::PS_I_VCSEL_20mA:
      Serial.println("20mA");
      break;
  }
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)

### `read_PS_with_AC()`

Read the vcnl36825t's Proximity sensor with Auto-Calibration. 

#### Syntax 

```
boolean vcnl36825t.read_PS_wirg_AC(uint16_t *ps, uint16_t *ps_ac)
```

#### Parameters

ps - point of uint16_t for proximity count.

ps_ac - point of uint16_t for auto-calibration count.

#### Returns

true on success, false on failure.

#### Example

```
uint16_t ps, ps_ac;

if (vcnl36825t.read_PS_with_AC(&ps, &ps_ac))
    Serial.print(ps);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read()](#read)
* [write()](#write)
* [read_PS()](#read_PS)
* [ALS_SD()](#ALS_SD)
* [PS_ST()](#PS_ST)
* [PS_INT()](#PS_INT)
* [PS_INT_with_threshold()](#PS_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [set_PS_I_VCSEL()](#set_PS_I_VCSEL)
* [get_PS_I_VCSEL()](#get_PS_I_VCSEL)
* [read_PS_wirg_AC()](#read_PS_with_AC)
